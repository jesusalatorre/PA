Actividad/                                                                                          000755  000765  000024  00000000000 13350021472 014771  5                                                                                                    ustar 00jesusalatorre                   staff                           000000  000000                                                                                                                                                                         Actividad/contador                                                                                  000755  000765  000024  00000021620 13350021471 016530  0                                                                                                    ustar 00jesusalatorre                   staff                           000000  000000                                                                                                                                                                         ����    �         �          H   __PAGEZERO                                                        �  __TEXT                                                    __text          __TEXT          �     �      �               �            __stubs         __TEXT          �     <       �              �           __stub_helper   __TEXT          �     t       �               �            __cstring       __TEXT          8     s       8                             __unwind_info   __TEXT          �     H       �                                8  __DATA                                                  __nl_symbol_ptr __DATA                                        
           __la_symbol_ptr __DATA               P                                  __common        __DATA          `     H                                        H   __LINKEDIT                            �                    "  �0                            �   �   h         X!     �"  �      P                                                X"                               /usr/lib/dyld             ,� � �3��u	rO��$       
  
 *              (  �   �                 8         2�   /usr/lib/libSystem.B.dylib      &      P!     )      X!                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      UH��H�� H�=�  1����E�    ��  �E��}� �   H�=E  �  �   �  H�}�1���H��   H���  �E��}� �   H�='  �\  �   �L  H�}�1���H��   H���G  �E��}� �   H�=�  �"  �   �  H�}�1���H�{   H���  �E��}� �   H�=�  ��   �   ��   H�u�H�}���   �E��}� �   H�=�  �   �   �   H�=�  � �   1��E��   �     UH��H�� �   H�}����   H�=I  �E��   �E�=,  ����   �    �  ���  �����H�=2  ������  � �(   H�=�  �E��=   1҉׉E��   ��%�  �%�  �%�  �%�  �%�  �%�  �%�  �%�  �%�  �%�  L�=  AS�%-  �h    �����h   �����h   �����h(   �����h>   ����hR   ����hf   ����h�   ����h�   ����h�   ����Mutex initialization failed Thread creation failed Thread join failed Thread joined INT_MAX = %d y contador = %d 
                         �  4   4   �      4                                             �     �     �     �     �                    $     .                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     "Z    @dyld_stub_binder Qr � r@_exit � r@_perror � r @_printf � r(@_pthread_create � r0@_pthread_exit � r8@_pthread_join � r@@_pthread_mutex_init � rH@_pthread_mutex_lock � rP@_pthread_mutex_unlock � rX@_sleep �       _  _mh_execute_header ;m ?thread_function Vwork_mutex `    ain Qicontador [ �  �  �   �     ��                    �          `     (           9     h     E             K             S             [             k             y             �             �             �             �             �                         	   
                     @            	   
                 __mh_execute_header _main _micontador _thread_function _work_mutex _exit _perror _printf _pthread_create _pthread_exit _pthread_join _pthread_mutex_init _pthread_mutex_lock _pthread_mutex_unlock _sleep dyld_stub_binder                                                                                                                    Actividad/._contador.c                                                                              000644  000765  000024  00000000413 13350021131 017151  0                                                                                                    ustar 00jesusalatorre                   staff                           000000  000000                                                                                                                                                                             Mac OS X            	   2   �                                           ATTR         �   C                  �   *  $com.apple.metadata:_kMDItemUserTags     �     com.apple.quarantine bplist00�                            	q/0081;5ba01a43;Firefox;                                                                                                                                                                                                                                                      Actividad/contador.c                                                                                000644  000765  000024  00000002774 13350021131 016750  0                                                                                                    ustar 00jesusalatorre                   staff                           000000  000000                                                                                                                                                                         //contador.c
//author: Alex Parra
//email aparra@itesm.mx
//Descripcion: Este es un programa sencillo el cual se usa para medir el tiempo que lleva contador el entero mÃ¡s grande alojado en un entero
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <limits.h>

void *thread_function(void *arg);
pthread_mutex_t work_mutex; /* protects both work_area and time_to_exit */
int micontador = 0;

int main(){
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_mutex_init(&work_mutex, NULL);
	if (res != 0) {
			perror("Mutex initialization failed");
			exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
	}

	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
			perror("Thread join failed");
			exit(EXIT_FAILURE);
	}
	printf("Thread joined");

	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    sleep(1);
    pthread_mutex_lock(&work_mutex);

		for (micontador; micontador < INT_MAX; micontador ++);
		printf( "INT_MAX = %d y contador = %d \n",INT_MAX, micontador);

    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}
    Actividad/._Makefile                                                                                000644  000765  000024  00000000322 13350021463 016643  0                                                                                                    ustar 00jesusalatorre                   staff                           000000  000000                                                                                                                                                                             Mac OS X            	   2   �      �                                      ATTR       �   �   *                  �   *  $com.apple.metadata:_kMDItemUserTags  bplist00�                            	                                                                                                                                                                                                                                                                                                              Actividad/Makefile                                                                                  000644  000765  000024  00000000236 13350021463 016432  0                                                                                                    ustar 00jesusalatorre                   staff                           000000  000000                                                                                                                                                                         all: contador thread5

contador: contador.c
	gcc contador.c -o contador -lpthread

thread5: thread5.c
	gcc thread5.c -o thread5 -lpthread

clean:
	rm -rf *.o
                                                                                                                                                                                                                                                                                                                                                                  Actividad/thread5                                                                                   000755  000765  000024  00000022314 13350021472 016255  0                                                                                                    ustar 00jesusalatorre                   staff                           000000  000000                                                                                                                                                                         ����    �      P  �          H   __PAGEZERO                                                        �  __TEXT                                                    __text          __TEXT          0     �      0               �            __stubs         __TEXT               T                     �           __stub_helper   __TEXT          \     �       \               �            __cstring       __TEXT          �     �       �                             __unwind_info   __TEXT          �     H       �                                �  __DATA                                                  __nl_symbol_ptr __DATA                                                   __got           __DATA                                                 __la_symbol_ptr __DATA               p                                  __common        __DATA          �     P                                       H   __LINKEDIT                            �                    "  �0             0           8     H!  x         �!     �#  (     P                                                (#                               /usr/lib/dyld             ���*�=���;|��%�$       
  
 *              (  �   0                 8         2�   /usr/lib/libSystem.B.dylib      &      �!     )      �!                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      UH��H��PH�=a	  1����E�    ��  �E��}� �   H�=�  �  �   �  H�}�1���H�_  H���  �E��}� �   H�=w  �p  �   �Z  H�=�  �  H�=l  �E� �O  �E��=�   ��4���   �   H�=�  �   H�  H��  H�=�  H�E��2  �E�H�=�  �  H�=z  ��� �E��!   H�=d  �  �   �E���  �E��   �   �����g���H�=4  ��  H�=�  �Eİ �  H�u�H�}��E��  �E��}� �   H�=�  �g  �   �Q  H�=�  � �U  H�=�  �E��^  1��E��*  @ UH��H��@�   H�}����P  H�=�  �E��5  �E�H�=�  H�5�  �   ���0  �� ��   H�=g  H�e  H�}�H���  H��H�}�H�ư �   H�=@  H�59  � �E���   �   �E���   H�=  �E��   �E�H�  ��� �0   H�=�  �   �   �E��   H�=�  �E��p   �E������1���H�=�  H��  ��     �  �I   1ɉωE��   ��%  �%  �%  �%  �%  �%  �%  �%  �%  �%  �%   �%"  �%$  �%&    L��  AS�%�  �h    �����h   �����h   �����h'   �����h5   ����hK   ����h_   ����hs   ����h�   ����h�   ����h�   ����h�   �x���h�   �n���h�   �d���Mutex initialization failed Thread creation failed Input some text. Enter 'end' to finish
 
Waiting for thread to finish...
 Thread join failed Thread joined
 end You input %d characters
                        0  4   4         4                                             l     v     �     �     �     �     �     �     �     �     �     �     �     �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             "^    @___stdinp Qr�@dyld_stub_binder �����������  r@_exit � r @_fgets � r(@_perror � r0@_printf � r8@_pthread_create � r@@_pthread_exit � rH@_pthread_join � rP@_pthread_mutex_destroy � rX@_pthread_mutex_init � r`@_pthread_mutex_lock � rh@_pthread_mutex_unlock � rp@_sleep � rx@_strlen � r�@_strncmp �       _  _mh_execute_header +main /t 4work_ ]    �  hread_function Sime_to_exit X �  �!  area lmutex q �!  �)   ��                    0          �     -   	  �     ;   	  �     F   	  �     R             \             b             i             q             y             �             �             �             �             �             �             �                         	                              	   
                                       @         	   
                                   __mh_execute_header _main _thread_function _time_to_exit _work_area _work_mutex ___stdinp _exit _fgets _perror _printf _pthread_create _pthread_exit _pthread_join _pthread_mutex_destroy _pthread_mutex_init _pthread_mutex_lock _pthread_mutex_unlock _sleep _strlen _strncmp dyld_stub_binder                                                                                                                                                                                                                                                                                                                          Actividad/._thread5.c                                                                               000644  000765  000024  00000000413 13350015013 016676  0                                                                                                    ustar 00jesusalatorre                   staff                           000000  000000                                                                                                                                                                             Mac OS X            	   2   �                                           ATTR         �   C                  �   *  $com.apple.metadata:_kMDItemUserTags     �     com.apple.quarantine bplist00�                            	q/0081;5ba01a0b;Firefox;                                                                                                                                                                                                                                                      Actividad/thread5.c                                                                                 000644  000765  000024  00000004050 13350015013 016462  0                                                                                                    ustar 00jesusalatorre                   staff                           000000  000000                                                                                                                                                                         #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_function(void *arg);
pthread_mutex_t work_mutex; /* protects both work_area and time_to_exit */

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main() {
    int res;
    pthread_t a_thread;
    void *thread_result;
    res = pthread_mutex_init(&work_mutex, NULL);
    if (res != 0) {
        perror("Mutex initialization failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_lock(&work_mutex);
    printf("Input some text. Enter 'end' to finish\n");
    while(!time_to_exit) {
        fgets(work_area, WORK_SIZE, stdin);
        pthread_mutex_unlock(&work_mutex);
        while(1) {
            pthread_mutex_lock(&work_mutex);
            if (work_area[0] != '\0') {
                pthread_mutex_unlock(&work_mutex);
                sleep(1);
            }
            else {
                break;
            }
        }
    }
    pthread_mutex_unlock(&work_mutex);
    printf("\nWaiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined\n");
    pthread_mutex_destroy(&work_mutex);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while(strncmp("end", work_area, 3) != 0) {
        printf("You input %d characters\n", strlen(work_area) -1);
        work_area[0] = '\0';
        pthread_mutex_unlock(&work_mutex);
        sleep(1);
        pthread_mutex_lock(&work_mutex);
        while (work_area[0] == '\0' ) {
            pthread_mutex_unlock(&work_mutex);
            sleep(1);
            pthread_mutex_lock(&work_mutex);
        }
    }
    time_to_exit = 1;
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        