namespace GodotGameAnalytics;

using Godot;
using Godot.Collections;

public enum ResourceFlowType
{
    Source = 1,
    Sink = 2
};

public enum ProgressionStatus
{
    Start = 1,
    Complete = 2,
    Fail = 3
};

public enum EGAErrorSeverity
{
    Debug = 1,
    Info = 2,
    Warning = 3,
    Error = 4,
    Critical = 5
};

public enum EGALoggerMessageType
{
    LogError = 0,
    LogWarning = 1,
    LogInfo = 2,
    LogDebug = 3
};


public enum AdAction
{
    Clicked = 1,
    Show = 2,
    FailedShow = 3,
    RewardReceived = 4
}

public enum AdType
{
    Video = 1,
    RewardedVideo = 2,
    Playable = 3,
    Interstitial = 4,
    OfferWall = 5,
    Banner = 6
}

public enum NoAdReason
{
    Null = 0,
    Unknown = 1,
    Offline = 2,
    NoFill = 3,
    InternalError = 4,
    InvalidRequest = 5,
    UnableToPrecache = 6
}

public static class GameAnalytics
{
    private static readonly GodotObject Singleton = Engine.HasSingleton("GameAnalytics") ? Engine.GetSingleton("GameAnalytics") : null;
    private static bool initialized, unavailable;

    private static readonly StringName
        MethodNameConfigureAvailableCustomDimensions01 = "configure_available_custom_dimensions01",
        MethodNameConfigureAvailableCustomDimensions02 = "configure_available_custom_dimensions02",
        MethodNameConfigureAvailableCustomDimensions03 = "configure_available_custom_dimensions03",

        MethodNameConfigureAvailableResourceCurrencies = "configure_available_resource_currencies",
        MethodNameConfigureAvailableResourceItemTypes = "configure_available_resource_item_types",

        MethodNameConfigureBuild = "configure_build",
        MethodNameConfigureAutoDetectAppVersion = "configure_auto_detect_app_version",
        MethodNameConfigureUserId = "configure_user_id",

        MethodNameInit = "init",

        MethodNameAddBusinessEvent = "add_business_event",
        MethodNameAddResourceEvent = "add_resource_event",
        MethodNameAddProgressionEvent = "add_progression_event",
        MethodNameAddDesignEvent = "add_design_event",
        MethodNameAddErrorEvent = "add_error_event",
        MethodNameAddAdEvent = "add_ad_event",

        MethodNameSetEnabledInfoLog = "set_enabled_info_log",
        MethodNameSetEnabledVerboseLog = "set_enabled_verbose_log",
        MethodNameSetEnabledManualSessionHandling = "set_enabled_manual_session_handling",
        MethodNameSetEnabledErrorReporting = "set_enabled_error_reporting",
        MethodNameSetEnabledEventSubmission = "set_enabled_event_submission",

        MethodNameSetCustomDimension01 = "set_custom_dimension01",
        MethodNameSetCustomDimension02 = "set_custom_dimension02",
        MethodNameSetCustomDimension03 = "set_custom_dimension03",

        MethodNameSetGlobalCustomEventFields = "set_global_custom_event_fields",

        MethodNameStartSession = "start_session",
        MethodNameEndSession = "end_session",
        MethodNameOnQuit = "on_quit",

        MethodNameGetRemoteConfigsValueAsString = "get_remote_configs_value_as_string",
        MethodNameIsRemoteConfigsReady = "is_remote_configs_ready",
        MethodNameGetRemoteConfigsContentAsString = "get_remote_configs_content_as_string";

    public static bool Init()
    {
        if (initialized) return true;
        if (unavailable) return false;

        if (Singleton == null)
        {
            GD.PushError("GameAnalytics not found in engine!");
            unavailable = true;
            return false;
        }

        return true;
    }

    public static bool Init(string gameKey, string secretKey)
    {
        if (!Init()) return false;

        try
        {
            Singleton.Call(MethodNameInit, gameKey, secretKey);
        }
        catch (System.Exception e)
        {
            GD.PushError(e);
            unavailable = true;
            return false;
        }

        initialized = true;
        return true;
    }

    public static void ConfigureAvailableCustomDimensions01(Array<string> customDimensions)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameConfigureAvailableCustomDimensions01, customDimensions);
    }
    public static void ConfigureAvailableCustomDimensions02(Array<string> customDimensions)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameConfigureAvailableCustomDimensions02, customDimensions);
    }
    public static void ConfigureAvailableCustomDimensions03(Array<string> customDimensions)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameConfigureAvailableCustomDimensions03, customDimensions);
    }

    public static void ConfigureAvailableResourceCurrencies(Array<string> resourceCurrencies)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameConfigureAvailableResourceCurrencies, resourceCurrencies);
    }
    public static void ConfigureAvailableResourceItemTypes(Array<string> resourceItemTypes)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameConfigureAvailableResourceItemTypes, resourceItemTypes);
    }

    public static void ConfigureBuild(string build)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameConfigureBuild, build);
    }
    public static void ConfigureAutoDetectAppVersion(bool enable)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameConfigureAutoDetectAppVersion, enable);
    }
    public static void ConfigureUserId(string userId)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameConfigureUserId, userId);
    }

    public static void AddBusinessEvent(
        string currency,
        int amount,
        string itemType,
        string itemId,
        string cartType,
        string receipt = null,
        bool autoFetchReceipt = false,
        string customFields = null,
        bool mergeFields = false)
    {
        Dictionary dict = new() {
            { "currency", currency },
            { "amount", amount },
            { "itemType", itemType },
            { "itemId", itemId },
            { "cartType", cartType },
            { "receipt", receipt }
        };
        if (autoFetchReceipt) dict.Add("autoFetchReceipt", autoFetchReceipt);
        if (customFields != null) dict.Add("customFields", customFields);
        if (mergeFields) dict.Add("mergeFields", mergeFields);

        AddBusinessEvent(dict);
    }
    public static void AddBusinessEvent(Dictionary options)
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't add event!");
            return;
        }

        Singleton.Call(MethodNameAddBusinessEvent, options);
    }
    public static void AddResourceEvent(
        ResourceFlowType flowType,
        string currency,
        float amount,
        string itemType,
        string itemId,
        string customFields = null,
        bool mergeFields = false)
    {
        Dictionary dict = new() {
            { "flowType", flowType.ToString() },
            { "currency", currency },
            { "amount", amount },
            { "itemType", itemType },
            { "itemId", itemId }
        };
        if (customFields != null) dict.Add("customFields", customFields);
        if (mergeFields) dict.Add("mergeFields", mergeFields);

        AddResourceEvent(dict);
    }
    public static void AddResourceEvent(Dictionary options)
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't add event!");
            return;
        }

        Singleton.Call(MethodNameAddResourceEvent, options);
    }

    public static void AddProgressionEvent(
        ProgressionStatus progressionStatus,
        string progression01,
        string progression02 = null,
        string progression03 = null,
        int? score = null,
        string customFields = null,
        bool mergeFields = false)
    {
        Dictionary dict = new() {
            { "progressionStatus", progressionStatus.ToString() },
            { "progression01", progression01 }
        };
        if (progression02 != null) dict.Add("progression02", progression02);
        if (progression03 != null) dict.Add("progression03", progression03);
        if (score != null) dict.Add("score", score.Value);
        if (customFields != null) dict.Add("customFields", customFields);
        if (mergeFields) dict.Add("mergeFields", mergeFields);

        AddProgressionEvent(dict);
    }
    public static void AddProgressionEvent(Dictionary options)
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't add event!");
            return;
        }

        Singleton.Call(MethodNameAddProgressionEvent, options);
    }
    public static void AddDesignEvent(
        string eventId,
        float? value = null,
        string customFields = null,
        bool mergeFields = false)
    {
        Dictionary dict = new() {
            { "eventId", eventId }
        };
        if (value != null) dict.Add("value", value.Value);
        if (customFields != null) dict.Add("customFields", customFields);
        if (mergeFields) dict.Add("mergeFields", mergeFields);

        AddDesignEvent(dict);
    }
    public static void AddDesignEvent(Dictionary options)
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't add event!");
            return;
        }

        Singleton.Call(MethodNameAddDesignEvent, options);
    }
    public static void AddErrorEvent(
        EGAErrorSeverity severity,
        string message = null,
        string customFields = null,
        bool mergeFields = false)
    {
        Dictionary dict = new() {
            { "severity", severity.ToString() },
            { "message", message }
        };
        if (customFields != null) dict.Add("customFields", customFields);
        if (mergeFields) dict.Add("mergeFields", mergeFields);

        AddErrorEvent(dict);
    }
    public static void AddErrorEvent(Dictionary options)
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't add event!");
            return;
        }

        Singleton.Call(MethodNameAddErrorEvent, options);
    }
    public static void AddAdEvent(
        AdAction adAction,
        AdType adType,
        string adSdkName,
        string adPlacement,
        bool sendDuration = false,
        int duration = -1,
        NoAdReason noAdReason = NoAdReason.Unknown,
        string customFields = null,
        bool mergeFields = false)
    {
        Dictionary dict = new() {
            { "adAction", adAction.ToString() },
            { "adType", adType.ToString() },
            { "adSdkName", adSdkName },
            { "adPlacement", adPlacement }
        };
        if (sendDuration) dict.Add("sendDuration", sendDuration);
        if (duration > -1) dict.Add("duration", duration);
        if (noAdReason != NoAdReason.Null) dict.Add("noAdReason", noAdReason.ToString());
        if (customFields != null) dict.Add("customFields", customFields);
        if (mergeFields) dict.Add("mergeFields", mergeFields);

        AddAdEvent(dict);
    }
    public static void AddAdEvent(Dictionary options)
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't add event!");
            return;
        }

        Singleton.Call(MethodNameAddAdEvent, options);
    }

    public static void SetEnabledInfoLog(bool enable)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameSetEnabledInfoLog, enable);
    }
    public static void SetEnabledVerboseLog(bool enable)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameSetEnabledVerboseLog, enable);
    }
    public static void SetEnabledManualSessionHandling(bool enable)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameSetEnabledManualSessionHandling, enable);
    }
    public static void SetEnabledErrorReporting(bool enable)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameSetEnabledErrorReporting, enable);
    }
    public static void SetEnabledEventSubmission(bool enable)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameSetEnabledEventSubmission, enable);
    }

    public static void SetCustomDimension01(string dimension)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameSetCustomDimension01, dimension);
    }
    public static void SetCustomDimension02(string dimension)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameSetCustomDimension02, dimension);
    }
    public static void SetCustomDimension03(string dimension)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameSetCustomDimension03, dimension);
    }

    public static void SetGlobalCustomEventFields(string customFields)
    {
        if (!Init()) return;

        Singleton.Call(MethodNameSetGlobalCustomEventFields, customFields);
    }

    public static void StartSession()
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't start session!");
            return;
        }

        Singleton.Call(MethodNameStartSession);
    }
    public static void EndSession()
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't end session!");
            return;
        }

        Singleton.Call(MethodNameEndSession);
    }
    public static void OnQuit()
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't quit!");
            return;
        }


        Singleton.Call(MethodNameOnQuit);
    }

    public static string GetRemoteConfigsValueAsString(Dictionary options)
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't get remote configs value!");
            return null;
        }

        return (string)Singleton.Call(MethodNameGetRemoteConfigsValueAsString, options);
    }
    public static bool IsRemoteConfigsReady()
    {
        if (!initialized) return false;

        return (bool)Singleton.Call(MethodNameIsRemoteConfigsReady);
    }
    public static string GetRemoteConfigsContentAsString()
    {
        if (!initialized)
        {
            GD.PrintErr("GameAnalytics was not initialized, can't get remote configs content!");
            return null;
        }

        return (string)Singleton.Call(MethodNameGetRemoteConfigsContentAsString);
    }
}