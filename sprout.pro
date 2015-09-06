TEMPLATE = subdirs
SUBDIRS = sprout-app sprout-c sprout-db

CONFIG += ordered

OTHER_FILES += \
    .gitignore \
    README.md

sproutapp.depends = sprout-c sprout-db
