/*
 *
 * Copyright (c) 2015-2016, Gregory M. Kurtzer
 * All rights reserved.
 *
 *
 * Copyright (c) 2015-2016, The Regents of the University of California,
 * through Lawrence Berkeley National Laboratory (subject to receipt of
 * any required approvals from the U.S. Dept. of Energy).
 * All rights reserved.
 *
 *
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define ENV_BIN "/bin/env"
#define SINGULARITY_BIN "singularity"
#define SINGULARITY_CMD "run"

#ident "Singularity Container"


int main(int argc, char **argv) {
    char *params[argc+3];
    int i;

    params[0] = (char *) malloc(strlen(ENV_BIN) + 1);
    memcpy(params[0], ENV_BIN, sizeof(ENV_BIN));
    params[1] = (char *) malloc(strlen(SINGULARITY_BIN) + 1);
    memcpy(params[1], SINGULARITY_BIN, sizeof(SINGULARITY_BIN));
    params[2] = (char *) malloc(strlen(SINGULARITY_CMD) + 1);
    memcpy(params[2], SINGULARITY_CMD, sizeof(SINGULARITY_CMD));
    for (i=0; i <= argc; i++) {
        params[i+3] = argv[i];
    }

    execv(ENV_BIN, params);
    return(255);
}
