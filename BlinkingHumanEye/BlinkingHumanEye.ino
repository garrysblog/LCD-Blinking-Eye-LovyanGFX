/*****************************************************************************
 * Animated Eye Display Program
 * 
 * Description:
 * This program creates a simple blinking eye animation on a circular 
 * 240x240 pixel display (SGC9A01 controller). The eye alternates between
 * an open state (shown for 3 seconds) and a closed/blinking state (shown
 * for 100ms), creating a realistic blinking effect.
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
#include "LGFX_SGC9A01_240x240.h"   // Display configuration for SGC9A01
#include "eye_open_center.h"        // Open eye image data array
#include "eye_closed.h"             // Closed eye image data array

// Display dimensions - matches the circular display size
const int IMAGE_WIDTH = 240;
const int IMAGE_HEIGHT = 240;

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
}

void loop() {
  // Display the open eye image
  // Parameters: x, y, width, height, image_data_array
  lcd.pushImage(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT, HumanEyeOpen240x240_data);
  delay(3000);  // Keep eye open for 3 seconds
  
  // Display the closed eye image (blink)
  lcd.pushImage(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT, HumanEyeClosed240x240_data);
  delay(100);   // Quick blink - eye closed for 100 milliseconds
  
  // Loop repeats, creating continuous blinking animation
}