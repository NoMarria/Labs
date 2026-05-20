#!/bin/bash
set -e
git checkout stg
git merge dev --no-ff -m "$(date +'%Y-%m-%d %H:%M:%S')"
TAG="stg-$(date +'%Y%m%d-%H%M%S')"
git tag "$TAG"
git push origin stg --tags
git checkout dev
