// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillAttributeSet/SkywalkerSkillAttributeSet.h"

USkywalkerSkillAttributeSet::USkywalkerSkillAttributeSet()
{
	SkillAttributeList = TArray<FSkywalkerSkillAttribute>();
}

// 增加技能属性，如果属性已存在则累加值
void USkywalkerSkillAttributeSet::AddSkillAttribute(ESkywalkerSkillAttributeType AttributeType, int32 AttributeValue)
{
	for (int32 i = 0; i < SkillAttributeList.Num(); i++)
	{
		if (SkillAttributeList[i].IsSameAttribute(AttributeType))
		{
			SkillAttributeList[i].AttributeValue += AttributeValue;
			return;
		}
	}
	
	FSkywalkerSkillAttribute SkillAttribute;
	SkillAttribute.AttributeType = AttributeType;
	SkillAttribute.AttributeValue = AttributeValue;
	SkillAttributeList.Add(SkillAttribute);
}

void USkywalkerSkillAttributeSet::AddSkillAttributeStruct(const FSkywalkerSkillAttribute& SkillAttribute)
{
	AddSkillAttribute(SkillAttribute.AttributeType, SkillAttribute.AttributeValue);
}

void USkywalkerSkillAttributeSet::AddSkillAttributeSet(USkywalkerSkillAttributeSet* OtherSkillAttributeSet)
{
	if (OtherSkillAttributeSet == nullptr)
	{
		return;
	}

	for (int32 i = 0; i < OtherSkillAttributeSet->SkillAttributeList.Num(); i++)
	{
		AddSkillAttributeStruct(OtherSkillAttributeSet->SkillAttributeList[i]);
	}
}

// 移除技能属性
void USkywalkerSkillAttributeSet::RemoveSkillAttribute(ESkywalkerSkillAttributeType AttributeType)
{
	for (int32 i = 0; i < SkillAttributeList.Num(); i++)
	{
		if (SkillAttributeList[i].IsSameAttribute(AttributeType))
		{
			SkillAttributeList.RemoveAt(i);
			return;
		}
	}
}

// 获取技能属性
FSkywalkerSkillAttribute USkywalkerSkillAttributeSet::GetSkillAttribute(ESkywalkerSkillAttributeType AttributeType)
{
	for (int32 i = 0; i < SkillAttributeList.Num(); i++)
	{
		if (SkillAttributeList[i].AttributeType == AttributeType)
		{
			return SkillAttributeList[i];
		}
	}
	return FSkywalkerSkillAttribute();
}

// 获取技能属性列表
TArray<FSkywalkerSkillAttribute> USkywalkerSkillAttributeSet::GetSkillAttributeList()
{
	return SkillAttributeList;
}

// 清理技能属性列表
void USkywalkerSkillAttributeSet::ClearSkillAttributeList()
{
	SkillAttributeList.Empty();
}

// 拷贝其他的技能属性集
void USkywalkerSkillAttributeSet::CopyFrom(USkywalkerSkillAttributeSet* OtherSkillAttributeSet)
{
	if (OtherSkillAttributeSet)
	{
		SkillAttributeList = OtherSkillAttributeSet->GetSkillAttributeList();
	}
}

// 是否有某个属性
bool USkywalkerSkillAttributeSet::HasSkillAttribute(ESkywalkerSkillAttributeType AttributeType)
{
	for (int32 i = 0; i < SkillAttributeList.Num(); i++)
	{
		if (SkillAttributeList[i].AttributeType == AttributeType)
		{
			return true;
		}
	}
	return false;
}
