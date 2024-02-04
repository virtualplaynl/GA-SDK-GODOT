extends Control

@export
var game_key_input: LineEdit
@export
var secret_key_input: LineEdit

@export
var enable_info_log: bool
@export
var enable_verbose_log: bool

@export
var buttons: Array[Button]

var GameAnalytics: Object = null

func _ready():
	if Engine.has_singleton("GameAnalytics"):
		GameAnalytics = Engine.get_singleton("GameAnalytics")
	
	if GameAnalytics == null:
		printerr("Error: GameAnalytics not found!")
	
	check_inputs()

func check_inputs():
	var invalid: bool = (GameAnalytics == null or len(game_key_input.text) != 32 or len(secret_key_input.text) != 40)
	for button in buttons:
		button.disabled = invalid

func test_init():
	if enable_info_log:
		GameAnalytics.set_enabled_info_log(true)
	if enable_verbose_log:
		GameAnalytics.set_enabled_verbose_log(true)
	
	GameAnalytics.init(game_key_input.text, secret_key_input.text)

func test_business():
	GameAnalytics.add_business_event({
		"currency": "USD",
		"amount": 100,
		"itemType": "boost",
		"itemId": "megaBoost",
		"cartType": "shop"
	})

func test_ad():
	GameAnalytics.add_ad_event({
		"adAction": "Show",
		"adType": "Banner",
		"adSdkName": "admob",
		"adPlacement": "[AD_PLACEMENT_OR_UNIT_ID]"
	})

func test_resource():
	GameAnalytics.add_resource_event({
		"flowType": "Sink",
		"currency": "Gems",
		"amount": 100,
		"itemType": "Boosters",
		"itemId": "BeamBooster5Pack",
	});
	GameAnalytics.add_resource_event({
		"flowType": "Source",
		"currency": "BeamBooster",
		"amount": 5,
		"itemType": "Gems",
		"itemId": "BeamBooster5Pack",
	});

func test_progression():
	GameAnalytics.add_progression_event({
		"progressionStatus": "Start",
		"progression01": "world01",
		"progression02": "stage01",
		"progression03": "level01",
	});

func test_error():
	GameAnalytics.add_error_event({
		"severity": "Critical",
		"message": "Something went bad in some of the smelly code!"
	})

func test_design():
	GameAnalytics.add_design_event({
		"eventId": "BossFights:FireLord:KillTimeUsed",
		"value": 234,
	});
