//
//  main.cpp
//  testing
//
//  Created by Nhan Nguyen on 4/18/16.
//  Copyright © 2016 Nhan Nguyen. All rights reserved.
//

//#include <iostream>
//#include <sstream>
//#include <string.h>
//#include <sys/stat.h>
//#include <stdlib.h>
//
//#ifdef _WIN32
//#include <direct.h>
//#include <io.h>
//#else
//#include <dirent.h>
//#include <unistd.h>
//#include <sys/param.h>
//#include <libgen.h>
//#endif
//
#include "dijkstra.h"
#include "list.h"
//
//#if defined _WIN32
//#define DIR_DELIMIT_CHAR				'\\'
//#define DIR_DELIMIT_CHARS			"\\"
//#else
//#define DIR_DELIMIT_CHAR				'/'
//#define DIR_DELIMIT_CHARS			"/"
//#endif
//#ifndef MAX_PATH_LEN
//#define MAX_PATH_LEN					4096
//#endif
//#ifndef MAX_FILE_LEN
//#define MAX_FILE_LEN					255
//#endif
//#define IS_FILE						1
//#define IS_DIRECTORY					2
//
//
//int is_file_directory(const char* pathname) {
//    struct stat buf;
//    char path[MAX_PATH_LEN];
//    strcpy(path, pathname);
//    if (path[strlen(path) - 1] == DIR_DELIMIT_CHAR)
//        path[strlen(path) - 1] = '\0';
//    
//#if defined _WIN32
//    if (_access(pathname, 0) == -1) {
//        return false;
//    }
//    _finddatai64_t c_file;
//    intptr_t file;
//    int result;
//    file = _findfirsti64(path, &c_file);
//    if (file == -1L)
//        result = -1;
//    else {
//        if (c_file.attrib & _A_SUBDIR)
//            result = IS_DIRECTORY;
//        else
//            result = IS_FILE;
//    }
//    _findclose(file);
//    return result;
//    
//#else
//    int flag = false;
//    if (access(pathname, F_OK))
//        return false;
//    if(strlen(path) == 1){
//    } else if(path[strlen(path)-1] == '/'){
//        path[strlen(path)-1]='\0';
//    }
//    lstat(path, &buf);
//    if(S_ISREG(buf.st_mode)){
//        return IS_FILE;
//    } else if(S_ISDIR(buf.st_mode)){
//        return IS_DIRECTORY;
//    } else {
//        return false;
//    }
//#endif
//}
//
//bool folder_exists(const char* path) {
//    struct stat st;
//    stat(path, &st);
//    return st.st_mode & S_IFDIR;
//}
//
//
//bool del_directory(const char *path){
//    switch(is_file_directory(path)){
//        case IS_FILE:
//            if(!remove(path)) return true;
//            else return false;
//            break;
//        case IS_DIRECTORY:
//#ifdef WIN32_
//#else
//            DIR*			dp;
//            struct dirent	*ep;
//            char			buf[512];
//            dp = opendir(path);
//            
//            while((ep=readdir(dp)) != NULL){
//                if(!strcmp(ep->d_name,".") || !strcmp(ep->d_name, ".."))
//                    continue;
//                sprintf(buf, "%s/%s", path, ep->d_name);
//                switch(is_file_directory(buf)){
//                    case IS_FILE:
//                        if(remove(buf)) return false;
//                        break;
//                    case IS_DIRECTORY:
//                        del_directory(buf);
//                }
//            }
//            closedir(dp);
//            rmdir(path);
//#endif
//            break;
//        default:
//            return false;
//            break;
//    }
//    return false;
//}


void tranverse(void *data){
    printf("traverse at %d\n", *(int *)data);
}

void delete_item(void *data){
    printf("Deleting at %d\n", *(int *)data);
    free(data);
}


int main(int argc, const char * argv[]) {
//    int grapth[10][10] = {
//        {0, 3,  0,  0,  0,  2,  0,  0,  0, 23   },
//        {0, 0,  23, 0,  0,  5,  0,  8,  0,  0   },
//        {0, 9,  0,  4,  0,  7,  0,  0,  0,  0   },
//        {5, 0,  0,  0,  24, 0,  0,  0,  3,  8   },
//        {0, 30, 0,  10, 0,  32, 0,  7,  0,  0   },
//        {6, 13, 0,  0,  4,  0,  0,  0,  12, 0   },
//        {0, 0,  5,  0,  4,  0,  0,  0,  0,  18  },
//        {0, 21, 0,  3,  0,  0,  0,  0,  24, 0   },
//        {9, 0,  0,  0,  8,  0,  0,  23, 0,  5   },
//        {0, 1,  0,  0,  24, 0,  0,  10, 0,  0   }
//    };
//    // insert code here...
//    int **tmp = (int **)malloc(10*sizeof(int*));
//    for(int i=0;i<10;i++){
//        tmp[i] = (int *) malloc(10*sizeof(int));
//        for(int j=0;j<10;j++)
//            tmp[i][j] = grapth[i][j];
//    }
//    std::cout << "Implementation of Dijkstra Algorithm, implemented by Nhan Nguyen\n";
//    Dijkstra<int> *d = new Dijkstra<int>();
//    int step;
//    int *p = d->findPath(tmp, 10, 8, 2, step);
//    if(p != NULL){
//        for(int i=0; i<step; i++){
//            std::cout << p[i] << " -> ";
//        }
//        std::cout << p[step] << std::endl;
//        delete p;
//    }
//    delete d;
//    return 0;
    
    //Triangular(45);
    
    L2_List_p myList = L2_LIST_INIT((char *)"Test list");
    
    for(int i=0; i<10; i++){
        int *value = new int;
        *value = i;
        //L2_ADD_TO_HEAD(myList, value);
        L2_ADD_TO_LAST(myList, value);
        //L2_ADD_TO_BEFORE_OF(myList, myList->anchor, value);
    }
    //
    L2_LIST_TRAVERSE(myList, &tranverse);
    L2_LIST_DESTROY(myList, &delete_item);
    return 0;
}