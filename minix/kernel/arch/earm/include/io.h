#ifndef _ARM_IO_H_
#define _ARM_IO_H_

#ifndef __ASSEMBLY__

#include <sys/types.h>

/* Access memory-mapped I/O devices */
#define mmio_read(a)    (*(volatile u32_t *)(a))
#define mmio_write(a,v) (*(volatile u32_t *)(a) = (v))
#define mmio_set(a,v)   mmio_write((a), mmio_read((a)) | (v))
#define mmio_clear(a,v) mmio_write((a), mmio_read((a)) & ~(v))

//OPTEE_START
static inline uint32_t read32(vaddr_t addr)
{
	return *(volatile uint32_t *)addr;
}

static inline void write32(uint32_t val, vaddr_t addr)
{
	*(volatile uint32_t *)addr = val;
}
//OPTEE_END

#endif /* __ASSEMBLY__ */

#endif /* _ARM_IO_H_ */
