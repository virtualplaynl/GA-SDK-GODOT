@tool
extends EditorPlugin

var export_plugin : AndroidExportPlugin

func _enter_tree():
	export_plugin = AndroidExportPlugin.new()
	add_export_plugin(export_plugin)


func _exit_tree():
	remove_export_plugin(export_plugin)
	export_plugin = null


class AndroidExportPlugin extends EditorExportPlugin:
	var _plugin_name = "GodotGameAnalytics Android"

	func _supports_platform(platform):
		if platform is EditorExportPlatformAndroid:
			return true
		return false

	func _get_android_libraries(platform, debug):
		if debug:
			return PackedStringArray(["gameanalytics-android/GodotGameAnalytics-debug.aar"])
		else:
			return PackedStringArray(["gameanalytics-android/GodotGameAnalytics-release.aar"])

	func _get_android_dependencies(platform, debug):
		return PackedStringArray(["com.gameanalytics.sdk:gameanalytics-android:6.4.3"])

	func _get_android_dependencies_maven_repos(platform, debug):
		return PackedStringArray(["https://maven.gameanalytics.com/release"])

	func _get_name():
		return _plugin_name
