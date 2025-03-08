// Detailed design notes and project overview

# Design Overview

This document describes the architecture of MicrogliaChemotaxisSim. The simulation integrates:
- Reaction–diffusion modeling for ATP and adenosine.
- Detailed microglial chemotaxis based on receptor kinetics (e.g., P2Y12) and intracellular signaling.
- Region-specific configurations to account for differences in extracellular matrix, diffusion rates, and cell density.
- Advanced numerical methods: Runge-Kutta integration with adaptive time-stepping and adaptive mesh refinement.
- Parallel computing utilities and visualization for real-time feedback.

Refer to `docs/research_notes.md` for literature sources and calibration details.