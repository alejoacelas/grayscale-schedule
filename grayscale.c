#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char**argv){
  void*h=dlopen("/System/Library/PrivateFrameworks/UniversalAccess.framework/UniversalAccess",RTLD_LAZY);
  if(!h){fprintf(stderr,"dlopen: %s\n",dlerror());return 1;}
  int(*get)(void)=dlsym(h,"UAGrayscaleIsEnabled");
  void(*set)(int)=dlsym(h,"UAGrayscaleSetEnabled");
  if(!get||!set){fprintf(stderr,"symbols missing\n");return 1;}
  if(argc>1 && strcmp(argv[1],"status")!=0){ set(strcmp(argv[1],"on")==0); }
  printf("%s\n", get()?"on":"off");
  return 0;
}
