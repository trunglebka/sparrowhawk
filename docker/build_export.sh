#!/usr/bin/env bash
if [ $# -lt 1 ]; then
    echo "Usage: $0 <out dir>" && exit 1
fi

out_dir=$1
[[ ! -d "${out_dir}" ]] || mkdir -p "${out_dir}"

#build in docker
build_date=$(date '+%Y%m%d')
img_tag=vivoice/sparrowhawk:"${build_date}"
docker build -t "${img_tag}" .

#clean out_dir
rm -rf "${out_dir:?}/"*

#copy file in docker image to host
id=$(docker create "${img_tag}")
docker cp "${id}":/usr/local/bin/normalizer_main "${out_dir}"
docker cp "${id}":/usr/local/bin/normalizer_worker "${out_dir}"
docker rm -v "${id}"

#copy resource file
[[ -d "${out_dir}/resources" ]] || mkdir "${out_dir}/resources"
rsync -r "../resources/" "${out_dir}/resources/" || exit 2
