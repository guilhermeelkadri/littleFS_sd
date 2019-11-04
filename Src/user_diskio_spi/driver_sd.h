//definição recursiva da biblioteca driver_sd
#ifndef __DRIVER_SD_H
#define __DRIVER_SD_H


//Includes
#include "stm32f1xx_hal.h"

// #include "" -> definir as constatnes de presença de sd
#define 	SD_CS_DETECTA_PORT			GPIOB
#define 	SD_CS_DETECTA_PIN			GPIO_PIN_0


//Structure definição da informação do SD card
typedef struct 
{
	uint32_t TipoCartao;          //especifica o tipo do cartão (MMC, SDC, Endereçamento de blocos)
	
	uint32_t VersaoCartao;        //especifica a versao do cartao

	uint32_t Classe;              //especifica a classe da classe do cartão

	uint32_t AddCartaoRelat;      //especifica endereço relativo do cartão

	uint32_t NumBloco;            //especifica a capacidade do cartão em blocos

	uint32_t TamanhoBloco;        //especifica tamanho do bloco em bytes

	uint32_t LogBlocoNum;         //especifica a capacidade logica do cartão em blocos

	uint32_t LogBlocoTamanho;     //especifica tamanho lógico do bloco em bytes

	uint32_t VelocidadeCartao;    //especifica velocidade do cartão 
}SD_CartaoInfoTypeDef;


//define de informação de sd card
#define SD_CartaoInfo SD_CartaoInfoTypeDef


/*         Constantes exportadas               */

/*Define do estatus de estrutura de informação do cartão SD*/
#define		MSD_OK						((uint8_t)0x00)
#define		MSD_ERRO					((uint8_t)0X01)
#define		MSD_ERRO_SD_NAO_INSERIDO 	                ((uint8_t)0X02)


/*Define dos estados de transferencia do cartão SD*/
#define 	SD_TRANSF_OK				((uint8_t)0x00)
#define 	SD_TRANSF_OCUPADA			((uint8_t)0x01)
#define 	SD_TRANSF_ERRO				((uint8_t)0x02)

#define 	SD_DATATIMEOUT				((uint32_t)100000000)

#define 	SD_PRESENTE				((uint8_t)0x01)
#define 	SD_NAO_PRESENTE				((uint8_t)0x00)		 				


/*             Funções exportadas             */
uint8_t sdInicia(void);
uint8_t sdItConfig(void);
uint8_t sdReadBlocos(uint32_t *pData, uint32_t readAdd, uint32_t NumDeBlocos);
uint8_t sdWriteBlocos(uint32_t *pData, uint32_t readAdd, uint32_t NumDeBlocos);
uint8_t sdApagar(uint32_t addInicial, uint32_t addFinal);
uint8_t sdDetecta(void);


#endif
