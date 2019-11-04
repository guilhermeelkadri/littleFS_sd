#include "stm32f1xx_hal.h"
/*falta declarar as funções dse Rx e Tx*/

//importa a propria biblioteca para carrregar as definições
#include "driver_sd.h"
#include <stdio.h>

extern SPI_HandleTypeDef hspi1;


uint8_t sdDetecta(void){
	uint8_t status = SD_PRESENTE;

	/* Verifica se há chip select no pino B0 */
	if(HAL_GPIO_ReadPin(SD_CS_DETECTA_PORT, SD_CS_DETECTA_PIN) == GPIO_PIN_RESET){
		status = SD_NAO_PRESENTE;
	} else {
		status = SD_PRESENTE;
	}

		printf("status detect = %i\n", status);//debug
		return status;
	}

uint8_t sdInicia(void){

	uint8_t sd_estado = MSD_OK;

		/*HAL para inicializar o SD*/
	sd_estado = HAL_SPI_Init(&hspi1);
	HAL_GPIO_WritePin(SD_CS_DETECTA_PORT, SD_CS_DETECTA_PIN, GPIO_PIN_SET);


	if(sd_estado == MSD_OK){
		   printf("status inicia = %i\n", sd_estado);//debug           
		} 

		/*checa se o cartão sd esta plugado no slot*/
		if (sdDetecta() != SD_PRESENTE) 
		{
			return MSD_ERRO;
		}
		return sd_estado;
	}


uint8_t sdItConfig(void){
	//configura o modo interrupção para a detecção do pino CS

	return (uint8_t)0;
}


uint8_t sdReadBlocos(uint32_t *pData, uint32_t readAdd, uint32_t numOfBlocks){

	uint8_t sd_estado = MSD_OK;

	if()

}













