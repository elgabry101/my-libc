#include "my_str.h"
#include <stdio.h>
#include <string.h>


static int min(int first,int second){
    int ret=0;
    if(first>second)
        ret=second;
    else
        ret=first;

    return ret;
}


void *memchr(const void *str, int c, size_t n){

    const unsigned char *srch = str;
    for(size_t i = 0; i < n ; i++)
    {
        if(*(srch+i)==(unsigned char)c)
            return (void*)(srch+i);
    }
    return NULL;
}


int memcmp(const void *str1, const void *str2, size_t n){

    unsigned char *s1=(unsigned char*)str1;
    unsigned char *s2=(unsigned char*)str2;

    for(size_t i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
        {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

void *memset(void *str, int c, size_t n){

    unsigned char *s=(unsigned char*)str;
    
    for(size_t i=0;i<n;i++)
    {
        s[i]=c;
    }
    return str;
}


void *memcpy(void *dest, const void * src, size_t n){

    const unsigned char *s=(unsigned char*)src;
    unsigned char *d=(unsigned char*)dest;

    for(size_t i=0;i<n;i++)
    {
        d[i]=s[i];
    }

    return dest;
}


void *memmove(void *dest, const void * src, size_t n){

    unsigned char *d=(unsigned char*)dest;
    const unsigned char *s=(unsigned char*)src;

    if(d<s)
    {
        for(size_t i=0;i<n;i++)
        {
            d[i]=s[i];
        }
    }
    else if(d>s)
    {
         for(size_t i=n-1;i>=0;i--)
        {
            d[i]=s[i];
        }
    }
    return dest;
}


size_t str_len(const char * str){
    size_t counter=0;
    while(str++!=NULL)
        counter++;

    return counter;
}


char *strcat(char *dest, const char *src){

    char *d = dest;
    while(*d!='\0')
    d++;
    while((*d++=*src++)!='\0');
    return dest;
}

char *strncat(char *dest, const char *src,size_t count){

    char *d = dest;
    while(*d!='\0')
    d++;
    while(count>0 && *src!='\0')
    {
        *d++=*src++;
        count--;
    }
    *d='\0';
    return dest;
}


char *strchr(const char *str, int c){
    char *ret=NULL;
    char ch=(char)c;
    while(*str!=c&&*str!='\0')
    {
        str++;
    }
    if(*str==c)
        ret=str;
    return ret;
}

char *strrchr(const char *str, int c)
{
    const char* ret=NULL;
    do
    {
        if(*str==(char)c)
            ret=str;
    }while(*str++!='\0');
    return(char *) ret;
}

int strcmp(const char *str1, const char *str2){

    while(*str1 == *str2 && *str1!='\0')
    {
        str1++;
        str2++;
    }
    return (unsigned char)*str1-(unsigned char)*str2;
}


int strncmp(const char *str1, const char *str2, size_t n){

    while(n > 0 && *str1 == *str2 && *str1!='\0')
    {
        str1++;
        str2++;
        n--;
    }

    if(n==0)
        return 0;
    return (unsigned char)*str1-(unsigned char)*str2;
}


int strcoll(const char *str1, const char *str2){
    //ignoring locale for now
    return strcmp(str1,str2);
}


char *strcpy(char *dest, const char *src){

    const char *s = src;
    char *d = dest;
    while((*d++=*s++)!='\0');
    return dest;
}


char *strncpy(char *dest, const char *src, size_t n){

    const char *s=src;
    char *d=dest;
    size_t cnt=0;
    while(cnt<n && s[cnt]!='\0')
    {
        d[cnt]=s[cnt];
        cnt++;
    }
    while(cnt<n)
    {
        d[cnt++]='\0';
        cnt++;
    }
    return dest;
}


char *strpbrk(const char *str1, const char *str2){

    size_t s=strcspn(str1,str2);
    if (str1[s]=='\0')
        return NULL;

    return (char*)str1+s;
}


char *strerror1(int errnum){

    return strerror(errnum);
}


size_t strspn(const char *str1, const char *str2)
{
    const unsigned char* s1=(const unsigned char*) str1;
    const unsigned char* s2=(const unsigned char*) str2;
    unsigned char table[256]={0};
    while (*s2)
        table[*s2++]=1;

    size_t count=0;
    while(table[*s1]==1)
    {
        count++;
        s1++;
    }

    return count;
}

size_t strcspn(const char *str1, const char *str2){

    const unsigned char* s1=(const unsigned char*) str1;
    const unsigned char* s2=(const unsigned char*) str2;
    unsigned char table[256]={0};
    while (*s2)
        table[*s2++]=1;

    size_t count=0;
    while(table[*s1]==0)
    {
        count++;
        s1++;
    }

    return count;
}

char *strstr(const char *haystack, const char *needle){

    size_t sz= str_len(needle);

    if(*needle=='\0')
        return (char*)haystack;
    while(*haystack!='\0')
    {

        if(*haystack==*needle)
        {
            size_t r=strncmp(haystack,needle,sz);
            if(r==0)
                break;
        }
        haystack++;
        
    }
    if(*haystack=='\0')
        return NULL;
    return (char*)haystack;
}


char *strtok(char *str, const char *delim){

    static char* s=NULL;
    if (str)
        s=str;

    if(s==NULL)
        return NULL;
    
    unsigned char table[256]={0};
    while (*delim)
        table[*delim++]=1;
    
    while(*s!='\0' && table[(unsigned char)*s]==1)
        s++;
    
    if(*s=='\0')
        return NULL;
    char *start=s;

    while(*s!='\0')
    {
        if(table[(unsigned char)*s]==1)
        {
            *s++='\0';
            break;
        }
        s++;
    
    }
    return start;
}


size_t strxfrm(char *dest, const char *src, size_t n){

    //skipping locale for now
    memmove(dest,src,n);

    return str_len(dest);

}
