如果修改了CubeMX再生成代码，请再修改回原来的FreeRTOSConfig.h


请将spi.h中HAL_SPI_MspInit()中对齐方式改为：
hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;