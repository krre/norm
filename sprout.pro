TEMPLATE = subdirs
SUBDIRS = sproutapp sproutc sproutdb

CONFIG += ordered

OTHER_FILES += \
    .gitignore \
    README.md

sproutapp.depends = sproutc sproutdb
