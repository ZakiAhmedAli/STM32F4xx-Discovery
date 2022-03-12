# This repository for my STM32F429ZI Discovery kit & STM32F407G-DISC1 Drivers

## Exploring STM32F407 and STMF429 Discovery Boards
The main purpose of this project is to get an insight into the STM32F407 Discovery Board & STM32F429 Discovery Board, which is an ARM Cortex M4 based Microcontroller. As I started working on STM32F4xx Discovery Board, initially it was difficult and confusing to understand and program this microcontroller because understanding internal structures and working of the microcontroller using datasheet of STM32F407VGT and STM32F429ZI MCUs is difficult especially if one is a beginner.


![image](https://user-images.githubusercontent.com/55850221/158016653-f6522093-2969-40c1-a5ff-5526cd36002d.png)

![61teTZnRWQL](https://user-images.githubusercontent.com/55850221/158016792-6aa8fe8f-9e29-45e7-a976-524c3e2a5d2c.jpg)


This project gives almost all the basic information needed to get started with STM32F407 Discovery Board and also development of driver code.
Hardware Used : STM32F4 DISCOVERY kit, for more information visit:

https://www.st.com/en/evaluation-tools/stm32f4discovery.html

https://www.st.com/en/microcontrollers-microprocessors/stm32f429zi.html

### The processor and peripherals talk via BUS-Interface. There are three busses available :-

I-BUS (Instruction Bus)
D-BUS (Data Bus)
S-BUS (System Bus)

I-BUS This bus connects the Instruction bus of the Cortex®-M4 with FPU(Floating point unit) core to the BusMatrix. This bus is used by the core to fetch instructions. The target of this bus is a memory containing code (internal Flash memory/SRAM or external memories through the FSMC/FMC).

D-BUS This bus connects the databus of the Cortex®-M4 with FPU to the 64-Kbyte CCM data RAM to the BusMatrix. This bus is used by the core for literal load and debug access. The target of this bus is a memory containing code or data (internal Flash memory or external memories through the FSMC/FMC).

S-BUS This bus connects the system bus of the Cortex®-M4 with FPU core to a BusMatrix. This bus is used to access data located in a peripheral or in SRAM. Instructions may also be fetched on this bus (less efficient than ICode). The targets of this bus are the internal SRAM1, SRAM2 and SRAM3, the AHB1 peripherals including the APB peripherals, the AHB2 peripherals and the external memories through the FSMC/FMC.



So instructions and data use I-bus and D-bus respectively, All the other peripheral uses System bus. The Cortex-M4 processor contains three external Advanced High-performance Bus (AHB)-Lite bus interface and one Advanced Peripheral Bus (APB) interface. The GPIOs are connected to AHB1 bus which has a maximum speed of 150Mhz and is divided into two buses as APB1 and APB2. APB1 runs at 42Mhz(max) and APB2 runs at 82Mhz(max). The different peripherals such as SPI, UART, TIMERs, ADCs, DACs, etc are connected to either APB1/APB2 buses. And the AHB2(168Mhz max) is connected to Camera and USB OTG interfaces, AHB3 is connected to External memory controller.
