/*
   Copyright 2016 Frank Hunleth

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <string.h>

#include "common.h"

extern const char *root_prefix;

FILE *fopen_helper(const char *filename, const char *mode)
{
    int prefix_len = strlen(root_prefix);
    if (prefix_len == 0) {
        // Normal case
        return fopen(filename, mode);
    } else {
        // Unit test case
        int len = strlen(filename) + prefix_len + 1;
        char path[len];
        memcpy(path, root_prefix, prefix_len);
        strcpy(&path[prefix_len], filename);
        return fopen(path, mode);
    }
}
