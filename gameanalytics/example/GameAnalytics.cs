namespace Lettryx;

using Godot;
using Godot.Collections;


public enum ProgressionStatus
{
    Start,
    Complete,
    Fail
}

public enum EGAErrorSeverity
{
    Debug,
    Info,
    Warning,
    Error,
    Critical
}

[Icon("GameAnalytics.svg")]
public partial class GameAnalytics : Node
{
    private static GameAnalytics instance;

    [Export] private string gameKey, secretKey;
    [Export] private bool enableInfoLog, enableVerboseLog;
    private static readonly GodotObject Singleton = Engine.HasSingleton("GameAnalytics") ? Engine.GetSingleton("GameAnalytics") : null;
    private static bool initialized, unavailable;

    public GameAnalytics() => instance = this;

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

        if (instance.enableInfoLog) Singleton.Call("setEnabledInfoLog", true);
        if (instance.enableVerboseLog) Singleton.Call("setEnabledVerboseLog", true);

        if (Singleton.Call("init", instance.gameKey, instance.secretKey) is Error)
            return false;

        initialized = true;
        return true;
    }

    public static Variant AddProgressionEvent(
        ProgressionStatus progressionStatus,
        string progression01,
        string progression02 = null,
        string progression03 = null,
        int? score = null,
        string customFields = null)
    {
        if (!Init()) return;

        Dictionary dict = new() {
            { "progressionStatus", progressionStatus.ToString() },
            { "progression01", progression01 }
        };
        if (progression02 != null) dict.Add("progression02", progression02);
        if (progression03 != null) dict.Add("progression03", progression03);
        if (score != null) dict.Add("score", score.Value);
        if (customFields != null) dict.Add("customFields", customFields);

        return Singleton.Call("addProgressionEvent", dict);
    }

    public static Variant AddDesignEvent(
        string eventId,
        float? value = null,
        string customFields = null)
    {
        if (!Init()) return;

        Dictionary dict = new() {
            { "eventId", eventId }
        };
        if (value != null) dict.Add("score", value.Value);
        if (customFields != null) dict.Add("customFields", customFields);

        return Singleton.Call("addDesignEvent", dict);
    }

    public static Variant AddErrorEvent(
        EGAErrorSeverity severity,
        string message = null,
        string customFields = null)
    {
        if (!Init()) return;

        Dictionary dict = new() {
            { "severity", severity.ToString() },
            { "message", message }
        };
        if (customFields != null) dict.Add("customFields", customFields);

        return Singleton.Call("addErrorEvent", dict);
    }
}