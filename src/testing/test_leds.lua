--[[ This function is executed every time you press the 'execute' button ]]
function init()
   reset()
end


--[[ This function is executed at each time step
     It must contain the logic of your controller ]]
function step()
   count = count + 1
   red_index = count
   green_index = count + 4
   blue_index = count + 8
   robot.leds.set_leds("black")
   robot.leds.set_led_index(math.fmod(red_index, 12) + 1, "red")
   robot.leds.set_led_index(math.fmod(green_index, 12) + 1, "green")
   robot.leds.set_led_index(math.fmod(blue_index, 12) + 1, "blue")
end

--[[ This function is executed every time you press the 'reset'
     button in the GUI. It is supposed to restore the state
     of the controller to whatever it was right after init() was
     called. The state of sensors and actuators is reset
     automatically by ARGoS. ]]
function reset()
   count = 0
end

--[[ This function is executed only once, when the robot is removed
     from the simulation ]]
function destroy()
   -- put your code here
end
