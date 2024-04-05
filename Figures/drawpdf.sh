#!/bin/bash
echo "--- Converting SVGs to PDFs ---"
for file in ./*.drawio.svg; do
    file_pdf="${file%.drawio.svg}.pdf"
    drawio -x --crop -f pdf -o $file_pdf $file
done
echo "-------------------------------"%
