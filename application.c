/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"
#include "MCAL_Layer/Timer0/hal_timr0.h"
#include "MCAL_Layer/Timer1/hal_timr1.h"
#include "MCAL_Layer/Timer2/hal_timr2.h"
#include "MCAL_Layer/Timer3/hal_timr3.h"
#include "MCAL_Layer/CCP/hal_ccp.h"
Std_ReturnType ret = E_NOT_OK;
volatile uint8 compare_flag;
void ccp1_default_interrupt_handler(void);
void timer3_default_interrupt_handler(void);

ccp_t ccp1_obj=
{
    .ccp_inst=CCP1_INST,
    .CCP1_InterruptHandler=ccp1_default_interrupt_handler,
    .ccp_mode=CCP_COMPARE_MODE_SELECTED,
    .ccp_mode_variant=CCP_COMPARE_MODE_TOGGLE_ON_MATCH,
    .ccp_pin.port=PORTC_INDEX,
    .ccp_pin.pin=GPIO_PIN2,
    .ccp_pin.direction=GPIO_DIRECTION_OUTPUT,
    
};

timer3_t timer_3=
{
    .TMR3_InterruptHandler=NULL,
    .priority=INTERRUPT_LOW_PRIORITY,
    .timer3_counter_mode=TIMER3_TIMER_MODE,
    .timer3_preload_value=0,
    .timer3_reg_wr_mode=TIMER3_RW_REG_8Bit_MODE,
    .timer3_prescaler_value=TIMER3_PRESCALER_DIV_BY_1,
};

int main()
{ 
    ret=CCP_Compare_Mode_Set_Value(&ccp1_obj,50000);
    ret=CCP_Init(&ccp1_obj);
    ret=Timer3_Init(&timer_3);
    
    
    while(1)
    {
        
    }

    
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}

void ccp1_default_interrupt_handler(void)
{
    Timer3_Write_Value(&timer_3,0);
    
}

void timer3_default_interrupt_handler(void)
{
   
}