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

var GAnalytics: Object = null

func _ready():
	if Engine.has_singleton("GameAnalytics"):
		GAnalytics = Engine.get_singleton("GameAnalytics")
	
	if GAnalytics == null:
		printerr("Error: GameAnalytics not found!")
	
	check_inputs()

func check_inputs():
	var invalid: bool = (GAnalytics == null or len(game_key_input.text) != 32 or len(secret_key_input.text) != 40)
	for button in buttons:
		button.disabled = invalid

func test_init():
	if enable_info_log:
		GAnalytics.setEnabledInfoLog(true)
	if enable_verbose_log:
		GAnalytics.setEnabledVerboseLog(true)
	
	GAnalytics.init(game_key_input.text, secret_key_input.text)

func test_business():
	GameAnalytics.addBusinessEvent({
		"currency": "USD",
		"amount": 100,
		"itemType": "boost",
		"itemId": "megaBoost",
		"cartType": "shop"
	})

func test_ad():
	GameAnalytics.addAdEvent({
		"adAction": "Show",
		"adType": "Banner",
		"adSdkName": "admob",
		"adPlacement": "[AD_PLACEMENT_OR_UNIT_ID]"
	})

func test_resource():
	GameAnalytics.addResourceEvent({
		"flowType": "Sink",
		"currency": "Gems",
		"amount": 100,
		"itemType": "Boosters",
		"itemId": "BeamBooster5Pack",
	});
	GameAnalytics.addResourceEvent({
		"flowType": "Source",
		"currency": "BeamBooster",
		"amount": 5,
		"itemType": "Gems",
		"itemId": "BeamBooster5Pack",
	});

func test_progression():
	GameAnalytics.addProgressionEvent({
		"progressionStatus": "Start",
		"progression01": "world01",
		"progression02": "stage01",
		"progression03": "level01",
	});

func test_error():
	GameAnalytics.addErrorEvent({
		"severity": "Critical",
		"message": "Something went bad in some of the smelly code!"
	})

func test_design():
	GameAnalytics.addDesignEvent({
		"eventId": "BossFights:FireLord:KillTimeUsed",
		"value": 234,
	});
