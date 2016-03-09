#include "stm32f30x_it.h"
#include "usb_istr.h"

void HardFault_Handler(void)
{
    for(;;);
}

void MemManage_Handler(void)
{
    for(;;);
}

void BusFault_Handler(void)
{
    for(;;);
}

void UsageFault_Handler(void)
{
    for(;;);
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
    USB_Istr();
}

void USBWakeUp_IRQHandler(void)
{
    EXTI_ClearITPendingBit(EXTI_Line18);
}