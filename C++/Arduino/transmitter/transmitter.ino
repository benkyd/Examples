uint32_t pwmPin = 8;
uint32_t maxDutyCount = 2;
uint32_t clkAFreq = 34000000ul;
uint32_t pwmFreq = 34000000ul; 

uint32_t channel;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);
  pmc_enable_periph_clk(PWM_INTERFACE_ID);
  PWMC_ConfigureClocks(clkAFreq, 0, VARIANT_MCK);
 
  PIO_Configure(
    g_APinDescription[pwmPin].pPort,
    g_APinDescription[pwmPin].ulPinType,
    g_APinDescription[pwmPin].ulPin,
    g_APinDescription[pwmPin].ulPinConfiguration);
 
  channel = g_APinDescription[pwmPin].ulPWMChannel;
  PWMC_ConfigureChannel(PWM_INTERFACE, channel , pwmFreq, 0, 0);
  PWMC_SetPeriod(PWM_INTERFACE, channel, maxDutyCount);
  PWMC_EnableChannel(PWM_INTERFACE, channel);
  PWMC_SetDutyCycle(PWM_INTERFACE, channel, 1);
  digitalWrite(13, 1);
}

void loop() {
  note(200, 300); // 300Hz for 3000ms


  delay(200);
}

void note(int duration, int f) {
  int del = (1000000 / f) / 2;
  int c = (duration * 1000) / del;
  bool x = true;
  for (long i = 0; i < c; i++) {
    if (x) {
      PWMC_SetDutyCycle(PWM_INTERFACE, channel, 1);
    }
    else {
      PWMC_SetDutyCycle(PWM_INTERFACE, channel, 0);
    }
    delayMicroseconds(del);
    x = !x;
  }
}
