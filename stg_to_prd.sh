#!/bin/bash
set -e
git checkout prd
git merge stg --no-ff -m "$(date +'%Y%m%d-%H%M%S')"
TAG="prd-$(date +'%Y%m%d-%H%M%S')"
git tag "$TAG"
git push origin prd --tags
git checkout dev
