# Tag replacement tool
  - program is very simple now and **QUALITY OF CODE** is terrible
  - this is only first version where I was only experimenting with how things work
  - I had a bunch of markdown files where I used simple links to empty notes (tag notes) as tags.
  - I wanted to change those pseudo tags to normal #tags.
  - I know the best way to do it would be simple bash script using grep, sed...
  - I am currently trying to pick up c++
  - **The most productive way to learn is to build something useful**
  - I have used filesystem, fstream, regex libraries
  - There's no meaningful commit history
  - Future work will be documented better

# Usage
  - place executable to directory containing .md files you want to modify
  - all .md files are found, "Tags: " line is found and "[[cpp]]" links are replaced with "\#cpp"
  - program creates new files with .md.new extension
  - all files have to be replaced manually - create backup first
  ```rm *.md```   
  - new files have to be renamed manually
  ```
  # Rename .md.new files
  for file in *.md.new; do
    mv "$file" "${file%.new}"
  done
```

# BUGS XD
  - if you run script multiple times on same files, it will modify already modified files and create .new.new.new duplicats

  
# Future improvements
  - make it modular for f*** sake XD
  - ehmm...fix that bug - remove old files (after prompt), and rename new files automatically
  - build CLI
  - expand functionality (Custom targets and replacements not just hard codded one use case)
  - consider speed for large file sets
