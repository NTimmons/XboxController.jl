module XboxController

struct Buttons
    a::Bool
    b::Bool
    x::Bool
    y::Bool
    leftStick::Bool
    rightStick::Bool
    leftShoulder::Bool
    rightShoulder::Bool
    back::Bool
    start::Bool
end

struct DPad
    up::Bool
    down::Bool
    right::Bool
    left::Bool
end

struct Triggers
    left::Float32
    right::Float32
end

struct ThumbSticks
    leftX::Float32
    leftY::Float32
    rightX::Float32
    rightY::Float32
end

struct ControllerState 
    connected::Bool
    packet::UInt64
    buttons::Buttons
    dpad::DPad
    thumbSticks::ThumbSticks
    triggers::Triggers
end 

function InitialiseControllerInput()
     return ccall((:Initialise, "WindowsXInput.dll"), Int32,
                    (Int32,), 0)
end

function BeginControllerInput()
     return ccall((:BeginControllerInput, "WindowsXInput.dll"), Cvoid,
                    (Int32,), 0)
end

function EndControllerInput()
     return ccall((:EndControllerInput, "WindowsXInput.dll"), Cvoid,
                    (Int32,), 0)
end

function GetControllerState(controllerID)::ControllerState
     return ccall((:GetControllerState, "WindowsXInput.dll"), ControllerState,
                    (Int32,), controllerID)
end

export InitialiseControllerInput, BeginControllerInput, EndControllerInput, GetControllerState
export ControllerState



end # module
