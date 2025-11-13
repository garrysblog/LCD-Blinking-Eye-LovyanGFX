/*****************************************************************************
 * Animated Eye Display Program
 * 
 * Description:
 * This program creates a realistic blinking eye animation on a circular 
 * 240x240 pixel display (SGC9A01 controller). The eye blinks at random
 * intervals to simulate natural human blinking behavior, with randomized
 * timing for both the open duration and blink duration.
 * 
 * Hardware:
 * - SGC9A01 240x240 circular LCD display
 * - Compatible microcontroller (ESP32, Arduino, etc.)
 * 
 * Dependencies:
 * - LovyanGFX library
 * - Custom display configuration (LGFX_SGC9A01_240x240.h)
 * - Eye image data files (eye_open_center.h, eye_closed.h)
 * 
 * The eye images should be stored as 16-bit RGB565 format arrays.
 *****************************************************************************/

#include <LovyanGFX.hpp>
#include "LGFX_SGC9A01_240x240.h"  // Display configuration for SGC9A01
#include "MonsterEyeOpen.h"        // Open eye image data array
#include "MonsterEyeClosed.h"      // Closed eye image data array

// Display dimensions - matches the circular display size
const int IMAGE_WIDTH = 240;
const int IMAGE_HEIGHT = 240;

// Timing constants for natural blinking behavior
const int MIN_OPEN_TIME = 1000;    // Minimum time eye stays open (1 second)
const int MAX_OPEN_TIME = 5000;    // Maximum time eye stays open (5 seconds)
const int MIN_BLINK_TIME = 100;    // Minimum blink duration (100 milliseconds)
const int MAX_BLINK_TIME = 500;    // Maximum blink duration (500 milliseconds)

// Create LCD object using LovyanGFX library
static LGFX lcd;

void setup() {
  // Initialize the LCD display
  lcd.init();
  
  // Set display orientation (0 = default, no rotation)
  lcd.setRotation(0);
  
  // Enable byte swapping for correct RGB565 color format
  // This ensures colors display correctly from the image data
  lcd.setSwapBytes(true); 
  
  // Clear the screen to black on startup
  lcd.fillScreen(TFT_BLACK);
  
  // Initialize random number generator with a noise value
  // This ensures different random patterns each time the program runs
  randomSeed(analogRead(0));
}

void loop() {
  // Display the open eye image
  // Parameters: x, y, width, height, image_data_array
  lcd.pushImage(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT, MonsterEyeOpen240x240_data);
  
  // Generate random delay for how long the eye stays open (1-5 seconds)
  int openDuration = random(MIN_OPEN_TIME, MAX_OPEN_TIME + 1);
  delay(openDuration);
  
  // Display the closed eye image (blink)
  lcd.pushImage(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT, MonsterEyeClosed240x240_data);
  
  // Generate random delay for how long the eye stays closed (100-500ms)
  int blinkDuration = random(MIN_BLINK_TIME, MAX_BLINK_TIME + 1);
  delay(blinkDuration);
  
  // Loop repeats, creating continuous natural blinking animation
}	