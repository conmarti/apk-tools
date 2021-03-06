apk-index(8)

# NAME

apk index - create repository index file from packages

# SYNOPSIS

*apk index* [<_options_>...] _packages_...

# DESCRIPTION

*apk index* creates a repository index from a list of package files. See
*apk-repositories*(8) for more information on repository indicies.

Generally, the resulting index must be cryptographically signed before *apk*
will accept it. See *abuild-sign*(1) for details.

# OPTIONS

*-d, --description* _TEXT_
	Add a description to the index. Upstream, this is used to add version
	information based on the git commit SHA of aports HEAD at the time of
	index generation.

*-o, --output* _FILE_
	Output generated index to _FILE_.

*-x, --index* _INDEX_
	Read an existing index from _INDEX_ to speed up the creation of the new
	index by reusing data when possible.

*--no-warnings*
	Disable the warning about missing dependencies. This happens when A,
	depends on package B, that does not have a provider in the indexed
	repository.

# AUTHORS

Natanael Copa <ncopa@alpinelinux.org>++
Timo Teräs <timo.teras@iki.fi>
