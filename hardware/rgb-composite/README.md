### The reason why AD724 is not suitable for this application

From datasheet:

> The AD724 can be used to convert the analog RGB output from a personal computer’s VGA card to the NTSC or PAL television standards. To accomplish this it is important to understand that the AD724 **requires interlaced RGB video** and clock rates that are consistent with those required by the television standards.

That's the case. STM32 LTDC can't output INTERLACED video signal.
