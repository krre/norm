TEMPLATE = subdirs
SUBDIRS = compiler sproutlib

compiler.depends = sproutlib

OTHER_FILES += \
    .gitignore \
    README.md
