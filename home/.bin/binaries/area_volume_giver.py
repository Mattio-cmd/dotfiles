#!/usr/bin/python

import sys

def calculate_area_and_volume(side_length, height):
    # Surface area of a rectangular prism with a square base
    area = 2 * (side_length ** 2) + 4 * side_length * height

    # Volume of the rectangular prism with a square base
    volume = side_length ** 2 * height

    return area, volume

def main():
    if len(sys.argv) != 3:
        print("Usage: python script.py <side_length> <height>")
        sys.exit(1)

    try:
        side_length = float(sys.argv[1])
        height = float(sys.argv[2])
    except ValueError:
        print("Error: Both inputs must be numbers.")
        sys.exit(1)

    area, volume = calculate_area_and_volume(side_length, height)

    print(f"Surface Area: {area} square units")
    print(f"Volume: {volume} cubic units")

if __name__ == "__main__":
    main()
