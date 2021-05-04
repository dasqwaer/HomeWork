#!/bin/bash

tr a-z A-Z < $1 | tr -s '\n' > $2
