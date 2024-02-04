using Godot;
using System;
using GodotGameAnalytics;

public partial class Example : Node
{
	[Export] private LineEdit gameKeyInput, secretKeyInput;
	[Export] private bool enableInfoLog, enableVerboseLog;
	[Export] private Button[] buttons;

	public void Init()
	{
		GameAnalytics.SetEnabledInfoLog(enableInfoLog);
		GameAnalytics.SetEnabledVerboseLog(enableVerboseLog);
		GameAnalytics.Init(gameKeyInput.Text, secretKeyInput.Text);

		CheckInputs();
	}

	public void CheckInputs()
	{
		bool invalid = !GameAnalytics.Init() || gameKeyInput.Text.Length != 32 || secretKeyInput.Text.Length != 40;
		foreach (Button button in buttons)
			button.Disabled = invalid;
	}

	public void TestBusiness()
		=> GameAnalytics.AddBusinessEvent("USD", 100, "boost", "megaBoost", "shop");
	public void TestAd()
		=> GameAnalytics.AddAdEvent(AdAction.Show, AdType.Banner, "admob", "AD_PLACEMENT", true, 13);
	public void TestResource()
	{
		GameAnalytics.AddResourceEvent(ResourceFlowType.Sink, "Gems", 100, "Boosters", "BeamBooster5Pack");
		GameAnalytics.AddResourceEvent(ResourceFlowType.Source, "BeamBooster", 5, "Gems", "BeamBooster5Pack");
	}
	public void TestProgression()
		=> GameAnalytics.AddProgressionEvent(ProgressionStatus.Complete, "world01", "stage01", "level01", 1234);
	public void TestError()
		=> GameAnalytics.AddErrorEvent(EGAErrorSeverity.Critical, "Something went bad in some of the smelly code!");
	public void TestDesign()
		=> GameAnalytics.AddDesignEvent("BossFights:FireLord:KillTimeUsed", 234.5f);
}
