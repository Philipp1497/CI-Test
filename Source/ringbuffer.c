#include "ringbuffer.h"
#include "stdbool.h"

#define FAIL 1;
#define SUCCESS 0;

struct ringbuffer
{
    char data[7];
    unsigned int head;
    unsigned int tail;
};
char zeichen ;
static struct ringbuffer buffer;

void initBuff()
{
    buffer.tail = 0;
    buffer.head = 0;

}
void addData(char byte)
{

    if(buffer.head > 7 && buffer.tail != 0)
    {
         buffer.head = 0;
    }

    if(buffer.head < 8)
    {
        buffer.data[buffer.head] = byte;
        buffer.head++;
    }

}

char getData()
{

    zeichen = buffer.data[buffer.tail] ;
    buffer.tail++;

    if(buffer.tail > 7 && buffer.head != 0 )
    {
        buffer.tail = 0;
    }
    else
    {
        return FAIL;
    }
    return zeichen;
}

bool isEmpty()
{
    if((buffer.head == 0 && buffer.tail == 0)||(buffer.head == buffer.tail))
    {
        return true;
    }
    else
    {
        return false;
    }
}
