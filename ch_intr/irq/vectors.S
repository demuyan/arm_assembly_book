/////begin ch_intr_asm
              .text
              .code 32

              .global vectors_start
              .global vectors_end       
/* ベクターテーブル */
vectors_start:                                 //-----(2-1) ここから
              LDR   PC, reset_handler_addr
              LDR   PC, undef_handler_addr
              LDR   PC, swi_handler_addr
              LDR   PC, prefetch_abort_handler_addr
              LDR   PC, data_abort_handler_addr
              B     .
              LDR   PC, irq_handler_addr       //-----(a-1)
              LDR   PC, fiq_handler_addr

reset_handler_addr: .word reset_handler
undef_handler_addr: .word halt
swi_handler_addr: .word halt
prefetch_abort_handler_addr: .word halt
data_abort_handler_addr: .word halt
irq_handler_addr: .word irq_handler            //-----(a-2)
fiq_handler_addr: .word halt                   //-----(2-1) ここまで
vectors_end:  

halt:         b     .

/*
 * リセット処理
 * 最初はスーパーバイザモードで起動する
 */
reset_handler: 

/* スーパーバイザモード時のスタック領域の先頭アドレスをセットする */
              LDR   sp, =stack_top      //-----(1)
/* ベクターテーブルをセットする */
              MOV   r0, #0x00           //-----(2) ここから
              LDR   r1, =vectors_start  
              LDR   r3, =vectors_end
keep_loading: 
              LDR   r2, [r1, #0x0]
              STR   r2, [r0, #0x0]
              ADD   r0, r0, #0x4
              ADD   r1, r1, #0x4
              CMP   r1, r3
              BNE   keep_loading        //-----(2) ここまで

/* ステータスレジスタを取得 */
              MRS   r0, cpsr            //-----(3)
/* IRQモードに切り替え */
              BIC   r1, r0, #0x1F       //-----(4) ここから
              ORR   r1, r1, #0x12
              MSR   cpsr, r1            //-----(4) ここまで
/* IRQモードへ切り替え */
/* IRQモード時のスタック領域の先頭アドレスをセットする */
              LDR   sp, =irq_stack_top  //-----(5) 

/* スーパーバイザモードに切り替え */      
              MSR   cpsr, r0            //-----(6) 
/* boot_main関数へ飛ぶ */
              BL    boot_main           //-----(7) 
              B     .

/*
 *  IRQ発生時
 */               
              .global irq_handler
irq_handler:                             
              PUSH  {r0-r12,lr}   //-----(b)
              BL    c_irq_handler                                    //-----(c)
              POP   {r0-r12,lr}   //-----(g)
              SUBS   pc,lr,#4                                         //-----(h)

/*
 *  IRQを許可する
 */ 
              .global enable_irq
enable_irq:   
              MRS   r0,cpsr
              BIC   r0,r0,#0x80
              MSR   cpsr_c,r0
              BX    lr
              
              .end
/////end
