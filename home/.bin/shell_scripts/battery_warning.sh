#!/bin/bash

# Check battery percentage
battery_level=$(acpi -b | awk -F ',' '{print $2}' | tr -d ' %')

# Set the threshold
threshold=35

# Compare battery level with the threshold
if [ "$battery_level" -le "$threshold" ]; then
    # Send notification using notify-send
    notify-send "Battery Warning" "Battery level is at $battery_level%. Please consider charging your laptop."
fi
