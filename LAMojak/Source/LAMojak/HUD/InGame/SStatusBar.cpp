// Fill out your copyright notice in the Description page of Project Settings.


#include "SStatusBar.h"
#include "SlateOptMacros.h"
#include "SSliderBar.h"
#include "SItemSkillBox.h"
#include "../UResourceManager.h"
#include "Widgets/Layout/SScaleBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SStatusBar::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(SScaleBox)
				.Stretch(EStretch::ScaleToFit)
				[
					SAssignNew(HealthBar, SSliderBar)
				]
			]

			+SVerticalBox::Slot()
			[
				SAssignNew(SkillBar0, SHorizontalBox)
			]

			+SVerticalBox::Slot()
			[
				SAssignNew(SkillBar1, SHorizontalBox)
			]
		]

		+SHorizontalBox::Slot()
		[
			SNew(SSpacer)
			.Size(FVector2D(10, 10))
		]


		+SHorizontalBox::Slot()
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(SScaleBox)
				.Stretch(EStretch::ScaleToFit)
				[
					SAssignNew(ManaBar, SSliderBar)
				]
			]

			+SVerticalBox::Slot()
			[
				SAssignNew(ItemBar0, SHorizontalBox)
			]

			+SVerticalBox::Slot()
			[
				SAssignNew(ItemBar1, SHorizontalBox)
			]
		]

	];

	GenerateSkillItemBoxs();

	for (int i = 0; i < 8; ++i)
	{
		UpdateImageKeyBox(i, true);
	}
	for (int i = 0; i < 10; ++i)
	{
		UpdateImageKeyBox(i, false);
	}
}

void SStatusBar::GenerateSkillItemBoxs()
{
	for (int i = 0; i < 4; ++i)
	{
		SkillBar0->AddSlot()
		.AutoWidth()
		[
			SNew(SItemSkillBox)
		];
	}

	for (int i = 0; i < 4; ++i)
	{
		SkillBar1->AddSlot()
		.AutoWidth()
		[
			SNew(SItemSkillBox)
		];
	}

	for (int i = 0; i < 6; ++i)
	{
		ItemBar0->AddSlot()
		.AutoWidth()
		[
			SNew(SItemSkillBox)
		];
	}

	for (int i = 0; i < 4; ++i)
	{
		ItemBar1->AddSlot()
		.AutoWidth()
		[
			SNew(SItemSkillBox)
		];
	}

}


void SStatusBar::SetSkillItemShortcuts()
{
	// [] ToDo
}

void SStatusBar::UpdateImageKeyBox(const int index, const bool IsSkill = true)
{
	if (index < 0 || index >= 8)
	{
		return;
	}

	int SkillIndex;
	UResourceManager* ResourceManager = UResourceManager::Get();
	TSharedPtr<SHorizontalBox>* SelectedBarPtr;
	if (IsSkill)
	{
		SelectedBarPtr = (index < 4)? &SkillBar0 : &SkillBar1;
		SkillIndex = (index < 4) ? index : index - 4;
	}
	else
	{
		SelectedBarPtr = (index < 6) ? &ItemBar0 : &ItemBar1;
		SkillIndex = (index < 6) ? index : index - 6;
	}

	TSharedPtr<SWidget> Widget = (*SelectedBarPtr)->GetChildren()->GetChildAt(SkillIndex);

	if (!Widget.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Widget is nullptr at index %d"), index);
		return;
	}

	TSharedPtr<SItemSkillBox> Box = StaticCastSharedPtr<SItemSkillBox>(Widget);

	const TArray<FString>& Names = (IsSkill)? SkillNames : ItemNames;
	const TArray<FString>& ShortCutKeys = (IsSkill)? SkillShortCutKeys : ItemShortCutKeys;

	if (Box.IsValid())
	{
		if (Names.Num() > index)
		{
			Box->SetImageBox(LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(Names[index])));
		}
		if (ShortCutKeys.Num() > index)
		{
			Box->SetKey(ShortCutKeys[index]);
		}
	}
}
