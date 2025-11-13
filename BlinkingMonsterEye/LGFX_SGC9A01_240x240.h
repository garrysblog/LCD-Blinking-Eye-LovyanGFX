/* GC9A01 configuration for ESP32 (240x240 circular display)

  SPI Wiring:
    Display SCL → ESP32 GPIO 18
    Display SDA → ESP32 GPIO 23
    Display CS → ESP32 GPIO 15
    Display DC (or RS) → ESP32 GPIO 5
    Display RES (or RESET) → ESP32 GPIO 4
    Display VCC → 3.3V or 5V
    Display GND → GND
    Display BLK → Not connected.
*/

class LGFX : public lgfx::LGFX_Device
{
  lgfx::Panel_GC9A01 _panel_instance;
  lgfx::Bus_SPI _bus_instance;

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();
      cfg.spi_host = VSPI_HOST;     // ESP32 VSPI (SPI3)
      cfg.spi_mode = 0;
      cfg.freq_write = 40000000;    // 40MHz (GC9A01 supports high speeds)
      cfg.freq_read  = 16000000;
      cfg.spi_3wire  = true;
      cfg.use_lock   = true;
      cfg.dma_channel = SPI_DMA_CH_AUTO;
      cfg.pin_sclk = 18;            // SPI SCK (connect to display SCL)
      cfg.pin_mosi = 23;            // SPI MOSI (connect to display SDA)
      cfg.pin_miso = 19;            // SPI MISO (not connected)
      cfg.pin_dc   = 5;             // Data/Command pin
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _panel_instance.config();
      cfg.pin_cs           = 15;    // Chip Select
      cfg.pin_rst          = 4;     // Reset
      cfg.pin_busy         = -1;    // Not used
      cfg.panel_width      = 240;   // Physical width (circular display)
      cfg.panel_height     = 240;   // Physical height (circular display)
      cfg.offset_x         = 0;     // X offset
      cfg.offset_y         = 0;     // Y offset
      cfg.offset_rotation  = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits  = 1;
      cfg.readable         = false;
      cfg.invert           = true;  // Color inversion (toggle if colors look wrong)
      cfg.rgb_order        = false; // RGB order for GC9A01
      cfg.dlen_16bit       = false;
      cfg.bus_shared       = true;

      _panel_instance.config(cfg);
    }

    setPanel(&_panel_instance);
  }
};