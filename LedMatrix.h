#include <Arduino.h>


#define TEXT_ALIGN_LEFT          0 // Text is aligned to left side of the display
#define TEXT_ALIGN_LEFT_END      1 // Beginning of text is just outside the right end of the display
#define TEXT_ALIGN_RIGHT         2 // End of text is aligned to the right of the display
#define TEXT_ALIGN_RIGHT_END     3 // End of text is just outside the left side of the display

class LedMatrix {

public:

    /**
     * Constructor.
     * numberOfDisplays: number of connected devices
     * slaveSelectPin: CS (or SS) pin connected to your ESP8266
     */
    LedMatrix(byte numberOfDevices, byte platchPin) ;

    /**
     * Initializes the SPI interface
     */
    void init();

    /**
     * Sets the intensity on all devices.
     * intensity: 0-15
     */
    void setIntensity(byte intensity);

    /**
     * Sets the width in pixels for one character.
     * Default is 7.
     */
    void setCharWidth(byte charWidth);

    /**
     * Sets the text alignment.
     * Default is TEXT_ALIGN_LEFT_END.
     *
     */
    void setTextAlignment(byte textAlignment);

    /**
     * Send a byte to all devices (convenience method).
     */
     void sendByte (const byte row, const byte col);

    /**
     * Turn on pixel at position (x,y).
     */
    void setPixel(byte x, byte y);

    /**
     * Clear the frame buffer.
     */
    void clear();

    /**
     * Draw the currently set text at the current offset.
     */
    void drawText();

    /**
     * Set the current text.
     */
    void setText(String text);

    /**
     * Set the text that will replace the current text after a complete scroll
     * cycle.
     */
    void setNextText(String nextText);

    /**
     * Set a specific column with a byte value to the framebuffer.
     */
    void setColumn(int column, byte value);

    /**
     * Writes the framebuffer to the displays.
     */
    void commit();

    /**
     * Scroll the text to the right.
     */
    void scrollTextRight();

    /**
     * Scroll the text to the left.
     */
    void scrollTextLeft();

    /**
     * Oscilate the text between the two limits.
     */
    void oscillateText();

private:
    byte * cols;
    byte spiregister[8];
    byte spidata[8];
    String myText;
    String myNextText;
    int myTextOffset = 1;
    int myTextAlignmentOffset = 0;
    int increment = -1;
    byte myNumberOfDevices = 0;
    byte myCharWidth = 7;
    byte myTextAlignment = 1;
    byte latchPin;
    byte brightness;
    void calculateTextAlignmentOffset();
};
