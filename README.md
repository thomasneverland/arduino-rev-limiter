# SIMPLE ARDUINO REV LIMITER 
This one is for **Fiat Cinquecento 899cc** only i guess

## How do i use that?!
IDK ***YET!!*** <br>
My idea was to use a cable (black/violet - pin 23 from ecu) that transmits the RPMs in volts to read the RPMs and then use a MOSFET (in my case IRF520N) to disrupt the ignition when the required RPM is reached

## Parts I've used
- **Arduino Nano** with screw shield for secure cable connections
- **IRF520N MOSFET** with driver module
- **33K ohms** and **47k ohms** resistors for voltage divider

## So, what's left?
- [x] Convert raw value from analogRead to voltage
- [x] Convert voltage to RPM
- [ ] Test RPM reading
- [ ] Find out where tf can i disrupt ignition
- [ ] Wire it
- [ ] Try it 🎉
