#!/bin/bash

echo "Uploading a Project Build to Coverity Scan"

echo "1. Clean the project -- make clean, rm cov-int"
make clean
rm -rf cov-int

echo "2. Build -- cov-build --dir cov-int make"
cov-build --dir cov-int make all

echo "3. Compress -- tar czvf myproject.tgz cov-int"
tar czvf myproject.tgz cov-int

echo "4. Send -- curl"
curl --form token=WpdCLu2PB6n1O7UgwxlPvg \
  --form email=jakub.zwolakowski@trust-in-soft.com \
  --form file=@/home/qba/git/micro-caesar-cipher/myproject.tgz \
  --form version="Version" \
  --form description="Description" \
  https://scan.coverity.com/builds?project=micro-caesar-cipher

echo "5. Clean up"
rm -rf cov-int
rm -f myproject.tgz

echo "6. Done!"
