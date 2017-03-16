#!/usr/bin/bash

echo "Make sure you have checked the repos !!!"

git checkout master
git pull github master
git pull bitbucket master
git checkout master