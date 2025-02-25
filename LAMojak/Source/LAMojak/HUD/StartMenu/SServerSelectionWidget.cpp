// Fill out your copyright notice in the Description page of Project Settings.

#include "SServerSelectionWidget.h"

#include "Widgets/Layout/SScaleBox.h"
#include "../SImageTextButton.h"

void SServerSelectionWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	GetServerInfo();

	UTexture2D* PanelTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Resources/Images/StartMenu/OuterBorder_1.OuterBorder_1"));
	FSlateBrush* PanelImageBrush = new FSlateBrush();
	PanelImageBrush->SetResourceObject(PanelTexture);
	PanelImageBrush->SetImageSize(FVector2D(256.f, 256.f));

	ChildSlot
	[
		SNew(SScaleBox)
		.Stretch(EStretch::ScaleToFit)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.VAlign(VAlign_Fill)
			.HAlign(HAlign_Fill)
			[
				SNew(SImage)
				.Image(PanelImageBrush)
				.ColorAndOpacity(FColor::White)
			]

			+SOverlay::Slot()
			[
				GenerateServerTextButtons()
			]

		]
	];
}

void SServerSelectionWidget::GetServerInfo()
{
	PlayersServerInfos.Add( FServerInfo("ServerA", "I", 1));
	PlayersServerInfos.Add( FServerInfo("ServerB", "J", 3));
	PlayersServerInfos.Add( FServerInfo("ServerC", "I", 1));
	PlayersServerInfos.Add( FServerInfo("ServerD", "I", 2));
}

TSharedRef<SVerticalBox> SServerSelectionWidget::GenerateServerTextButtons()
{
	UTexture2D* OodButtonTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Resources/Images/StartMenu/insideBorder_0.insideBorder_0"));
	FSlateBrush* OddButtonImageBrush = new FSlateBrush();
	OddButtonImageBrush->SetResourceObject(OodButtonTexture);
	OddButtonImageBrush->SetImageSize(FVector2D(256.f, 64.f));

	UTexture2D* EvenButtonTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Resources/Images/StartMenu/insideBorder_1.insideBorder_1"));
	FSlateBrush* EvenButtonImageBrush = new FSlateBrush();
	EvenButtonImageBrush->SetResourceObject(EvenButtonTexture);
	EvenButtonImageBrush->SetImageSize(FVector2D(256.f, 64.f));

	USlateWidgetStyleAsset* ButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, TEXT("/Game/Resources/Brushes/BasicButtonBrush.BasicButtonBrush"));

	UObject* TitleFont;
	TitleFont = LoadObject<UObject>(nullptr, TEXT("/Game/Resources/Fonts/Danjo-bold-Regular_Font.Danjo-bold-Regular_Font"));
	FSlateFontInfo TitleStyleText = FSlateFontInfo(TitleFont, 35);

	UObject* ContentsFont;
	ContentsFont = LoadObject<UObject>(nullptr, TEXT("/Game/Resources/Fonts/GowunDodum-Regular_Font.GowunDodum-Regular_Font"));
	FSlateFontInfo ContentsStyleText = FSlateFontInfo(ContentsFont, 30);


	TSharedRef<SVerticalBox> ServerList = SNew(SVerticalBox);
	// Title
	ServerList->AddSlot()
	.AutoHeight()
	.Padding(5.0f)
	.HAlign(HAlign_Center)
	[
		SNew(STextBlock)
			.Text(FText::FromString("Select Server"))
			.Font(TitleStyleText)
			.ColorAndOpacity(FColor::Black)
	];
	
	// Categories
	ServerList->AddSlot()
		.AutoHeight()
		.Padding(5.0f)
		.HAlign(HAlign_Center)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().Padding(30.0f).HAlign(HAlign_Center).AutoWidth()[SNew(STextBlock).Text(FText::FromString("Server Name")).Font(ContentsStyleText).ColorAndOpacity(FColor::Yellow)]
			+ SHorizontalBox::Slot().Padding(30.0f).HAlign(HAlign_Center).AutoWidth()[SNew(STextBlock).Text(FText::FromString("Status")).Font(ContentsStyleText).ColorAndOpacity(FColor::Yellow)]
			+ SHorizontalBox::Slot().Padding(30.0f).HAlign(HAlign_Center).AutoWidth()[SNew(STextBlock).Text(FText::FromString("Character")).Font(ContentsStyleText).ColorAndOpacity(FColor::Yellow)]
		];

	// Server List
	for (int Index = 0; Index < PlayersServerInfos.Num(); Index++)
	{
		const FServerInfo& Server = PlayersServerInfos[Index];
		FSlateBrush* ButtonBrush = (Index % 2 == 0) ? EvenButtonImageBrush : OddButtonImageBrush;
		FColor TextColor = (Index % 2 == 0) ? FColor::Black : FColor::White;

		ServerList->AddSlot()
			.AutoHeight()
			.Padding(5.0f)
			.VAlign(VAlign_Fill)
			.HAlign(HAlign_Fill)
			[
				SNew(SButton)
					.ButtonStyle(ButtonStyle)
					.HAlign(HAlign_Fill)
					[
						SNew(SOverlay)

						+ SOverlay::Slot()
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
						[
							SNew(SImage)
							.Image(ButtonBrush)
						]

						+ SOverlay::Slot()
						.Padding(5.f)
						.HAlign(HAlign_Fill)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot().Padding(10.0f).HAlign(HAlign_Center)[SNew(STextBlock).Text(FText::FromString(Server.Name)).Font(ContentsStyleText).ColorAndOpacity(TextColor)]
							+ SHorizontalBox::Slot().Padding(10.0f).HAlign(HAlign_Center)[SNew(STextBlock).Text(FText::FromString(Server.Status)).Font(ContentsStyleText).ColorAndOpacity(TextColor)]
							+ SHorizontalBox::Slot().Padding(10.0f).HAlign(HAlign_Center)[SNew(STextBlock).Text(FText::AsNumber(Server.NumberOfCharacter)).Font(ContentsStyleText).ColorAndOpacity(TextColor)]
						]
					]
			];
	}

	// Select Button
	ServerList->AddSlot()
		.Padding(5.0f)
		.HAlign(HAlign_Center)
		[
			SNew(SButton)
			.Content()
			[				
				SNew(STextBlock)
				.Text(FText::FromString("Enter"))
				.Font(ContentsStyleText)
			]
		];
	return ServerList;
}
