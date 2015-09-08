TEMPLATE = subdirs
SUBDIRS = sprout-db sprout-c sprout-app

sprout-c.depends = sprout-db
sprout-app.depends = sprout-db
sprout-app.depends = sprout-c

OTHER_FILES += \
    .gitignore \
    README.md
