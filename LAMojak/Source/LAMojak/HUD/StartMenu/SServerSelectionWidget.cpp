// Fill out your copyright notice in the Description page of Project Settings.

#include "SServerSelectionWidget.h"

#include "Widgets/Layout/SScaleBox.h"
#include "../TextManager.h"
#include "../UResourceManager.h"
#include "../SImageTextButton.h"

#define LOCTEXT_NAMESPACE "YourNamespace"

void SServerSelectionWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	GetServerInfo();

	UResourceManager* ResourceManager = UResourceManager::Get();
	UTexture2D* PanelTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath("ServerSelect-MainPanel.ServerSelect-MainPanel"));
	FSlateBrush* PanelImageBrush = new FSlateBrush();
	PanelImageBrush->SetResourceObject(PanelTexture);

	PanelImageBrush->SetImageSize(FVector2D(PanelTexture->GetSizeX()*1.5f, PanelTexture->GetSizeY()));

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
			.Padding(10.f)
			[
				GenerateServerTextButtons()
			]

		]
	];
}

void SServerSelectionWidget::GetServerInfo()
{
	PlayersServerInfos.Add(FServerInfo(LOCTEXT("Abraschud", "아브렐슈드"), LOCTEXT("ServerBusy", "혼잡"), 1));
	PlayersServerInfos.Add(FServerInfo(LOCTEXT("Nanab", "나나브"), LOCTEXT("ServerNormal", "원활"), 3));
	PlayersServerInfos.Add(FServerInfo(LOCTEXT("Kadan", "카단"), LOCTEXT("ServerNormal", "원활"), 1));
	PlayersServerInfos.Add(FServerInfo(LOCTEXT("Kazeros", "카제로스"), LOCTEXT("ServerBusy", "혼잡"), 2));
}


TSharedRef<SVerticalBox> SServerSelectionWidget::GenerateServerTextButtons()
{
	UResourceManager* ResourceManager = UResourceManager::Get();

	// Load button textures via ResourceManager
	UTexture2D* OddButtonTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath("insideBorder_0.insideBorder_0"));
	FSlateBrush* OddButtonImageBrush = new FSlateBrush();
	OddButtonImageBrush->SetResourceObject(OddButtonTexture);
	OddButtonImageBrush->SetImageSize(FVector2D(256.f, 64.f));

	UTexture2D* EvenButtonTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath("insideBorder_1.insideBorder_1"));
	FSlateBrush* EvenButtonImageBrush = new FSlateBrush();
	EvenButtonImageBrush->SetResourceObject(EvenButtonTexture);
	EvenButtonImageBrush->SetImageSize(FVector2D(256.f, 64.f));

	// Load button style from ResourceManager
	USlateWidgetStyleAsset* ButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, *ResourceManager->GetBrushAssetPath("BasicButtonBrush.BasicButtonBrush"));

	// Load fonts from ResourceManager
	UObject* TitleFont = LoadObject<UObject>(nullptr, *ResourceManager->GetFontAssetPath("Danjo-bold-Regular_Font.Danjo-bold-Regular_Font"));
	FSlateFontInfo TitleStyleText = FSlateFontInfo(TitleFont, 25);

	UObject* ContentsFont = LoadObject<UObject>(nullptr, *ResourceManager->GetFontAssetPath("GowunDodum-Regular_Font.GowunDodum-Regular_Font"));
	FSlateFontInfo ContentsStyleText = FSlateFontInfo(ContentsFont, 20);

	// Localized strings for columns and buttons
	const FText ServerSelectionText = UTextManager::Get()->GetLocalizedText("ServerSelectionTitle");
	const FText ServerColumnText = UTextManager::Get()->GetLocalizedText("ServerColumn");
	const FText StatusColumnText = UTextManager::Get()->GetLocalizedText("StatusColumn");
	const FText CharacterColumnText = UTextManager::Get()->GetLocalizedText("CharacterColumn");
	const FText EnterButtonText = UTextManager::Get()->GetLocalizedText("EnterButton");



	TSharedRef<SVerticalBox> ServerList = SNew(SVerticalBox);
	// Title
	ServerList->AddSlot()
	.AutoHeight()
	.Padding(5.0f)
	.HAlign(HAlign_Center)
	[
		SNew(STextBlock)
			.Text(ServerSelectionText)
			.Font(TitleStyleText)
			.ColorAndOpacity(FColor::White)
	];
	
	// Categories
	ServerList->AddSlot()
		.AutoHeight()
		.Padding(5.0f)
		.HAlign(HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().Padding(30.0f).HAlign(HAlign_Center).FillWidth(3)[SNew(STextBlock).Text(ServerColumnText).Font(ContentsStyleText).ColorAndOpacity(FColor::Yellow)]
			+ SHorizontalBox::Slot().Padding(30.0f).HAlign(HAlign_Center).FillWidth(1)[SNew(STextBlock).Text(StatusColumnText).Font(ContentsStyleText).ColorAndOpacity(FColor::Yellow)]
			+ SHorizontalBox::Slot().Padding(30.0f).HAlign(HAlign_Center).FillWidth(1)[SNew(STextBlock).Text(CharacterColumnText).Font(ContentsStyleText).ColorAndOpacity(FColor::Yellow)]
		];

	// Server List
	for (int Index = 0; Index < PlayersServerInfos.Num(); Index++)
	{
		const FServerInfo& Server = PlayersServerInfos[Index];
		FSlateBrush* ButtonBrush = (Index % 2 == 0) ? EvenButtonImageBrush : OddButtonImageBrush;
		FColor TextColor = (Index % 2 == 0) ? FColor::Black : FColor::White;
		
		// 상태에 따라 색상 변경 (혼잡: 노란색, 원활: 초록색)
		FColor ServerStatusColor = (Server.Status.EqualTo(LOCTEXT("ServerBusy", "혼잡"))) ? FColor::Yellow : FColor::Green;

		ServerList->AddSlot()
			.AutoHeight()
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
					.HAlign(HAlign_Fill)
					[	
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot().FillWidth(3).Padding(30.f, 1.0f).HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text(Server.Name).Font(ContentsStyleText).ColorAndOpacity(TextColor)]
						+ SHorizontalBox::Slot().FillWidth(1).Padding(30.f, 1.0f).HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text(Server.Status).Font(ContentsStyleText).ColorAndOpacity(ServerStatusColor)]
						+ SHorizontalBox::Slot().FillWidth(1).Padding(30.f, 1.0f).HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text(FText::AsNumber(Server.NumberOfCharacter)).Font(ContentsStyleText).ColorAndOpacity(TextColor)]
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
			.ContentPadding(10.f)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.Content()			
			[				
				SNew(STextBlock)
				.Text(EnterButtonText)
				.Font(TitleStyleText)
			]
		];
	return ServerList;
}

#undef LOCTEXT_NAMESPACE