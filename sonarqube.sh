#! /bin/bash

build-wrapper-linux-x86-64 --out-dir build_wrapper_output_directory make clean all

sonar-scanner \
  -Dsonar.projectKey=micro-caesar-cipher \
  -Dsonar.sources=. \
  -Dsonar.cfamily.build-wrapper-output=build_wrapper_output_directory \
  -Dsonar.host.url=http://localhost:9000 \
  -Dsonar.login=d715c0a12e7f87b66375a00ebe46802f5640def3
