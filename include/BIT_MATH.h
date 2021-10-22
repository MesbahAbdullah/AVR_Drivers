/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 29 Jul 2020                             */
/* Version     : V01                                     */
/* Brief       : BIT Math library                        */
/*********************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

/* set bit in register */
#define SET_BIT(VAR,BIT)        VAR |=  (1<<(BIT)  )

/* clear bit in register */
#define CLR_BIT(VAR,BIT)        VAR &= ~(1<<(BIT)  )

/* get value of bit in register */
#define GET_BIT(VAR,BIT)        ((VAR >> BIT) & 1  )

/* toggel bit in register */
#define TOG_BIT(VAR,BIT)        VAR ^=  (1 <<(BIT) )

/* check if bit is set will return 1 in case of  bit =1 */
#define BIT_IS_SET(REG,BIT)     ((REG & (1<<BIT)))

/* check if bit is clear will return 1 in case of  bit =0 */
#define BIT_IS_CLEAR(REG,BIT)   ( !(REG & (1<<BIT)))

/* Rotate register right with specific num of rotates */
#define ROR(REG,num)            ( REG= (REG>>num) | (REG<<(32-num)) )

/* Rotate register left with specific num of rotates */
#define ROL(REG,num)            ( REG= (REG<<num) | (REG>>(32-num)) )

#endif  

