# Arduino Uno Keyboard Service

Using the Arduino Uno's USB chip, we can do cool USB things - like emulate a keyboard.

This repo is the code for the USB 16u2 chip. It must be flashed with Hoodloader2 for this to work.

When running this code on your chip, it will listen in on the serial connection with a baud rate of `115200`.

It will accept a char.

So, to send a signal with a command, you'll need some code like this...

```cpp
void setup() {
  Serial.begin(baudRate);
}

void loop() {
  // send the command 'a' to the USB chip.
  Serial.write('a');
}
```

## Supported commands

| Command Name       | Char |
|--------------------|------|
| Sleep (Windows 10) | a    |  