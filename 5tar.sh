#!/bin/bash

touch file1
tar cf archive.tar file1
tar tf archive.tar

echo "---"

touch file2
tar rf archive.tar file2
tar tf archive.tar

echo "---"

touch file3
tar rf archive.tar file3
tar tf archive.tar

echo "---"

tar f archive.tar --delete file2
tar tf archive.tar

