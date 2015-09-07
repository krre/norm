TEMPLATE = subdirs
SUBDIRS = sprout-c sprout-db sprout-app

sprout-app.depends = sprout-c
sprout-app.depends = sprout-db

OTHER_FILES += \
    .gitignore \
    README.md
