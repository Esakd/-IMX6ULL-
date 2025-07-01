#ifndef UART_H
#define UART_H
#ifdef __cplusplus
extern "C"{
#endif
typedef struct uart_hardware_cfg {
    unsigned int baudrate;      /* 波特率     */
    unsigned char dbit;         /* 数据位     */
    char parity;                /* 奇偶校验 */
    unsigned char sbit;         /* 停止位 */
} uart_cfg_t;

int uart_init(const char *device);
int uart_cfg(const uart_cfg_t *cfg,int fd);
#ifdef __cplusplus
}
#endif
#endif
